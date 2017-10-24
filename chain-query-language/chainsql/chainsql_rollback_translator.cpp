#include <chainsql/chainsql_rollback_translator.h>
#include <chainsql/chainsql_types.h>
#include <chainsql/exceptions.h>
#include <string>
#include <sstream>
#include <vector>
#include <boost/algorithm/string.hpp>

namespace chainsql
{
	RollbackTranslator::RollbackTranslator(std::string sql_table_prefix)
		: _sql_table_prefix(sql_table_prefix)
	{

	}

	RollbackTranslator::~RollbackTranslator()
	{

	}

	static std::string wrap_column_name(const std::string &col_name)
	{
		return std::string("`") + col_name + "`";
	}

	// 字符串用于sql中要转义(\要转成\\, '要转成\')
	static std::string escape_sql_string(std::string text)
	{
		boost::replace_all(text, "\\", "\\\\");
		boost::replace_all(text, "'", "\\'");
		return text;
	}

	static std::string column_value_to_sql(const SqlValue &sql_value)
	{
		if (sql_value.is_null)
			return "null";
		switch (sql_value.type)
		{
		case SqlColumnTypeEnum::SCT_BIGINT:
		case SqlColumnTypeEnum::SCT_INT:
			return std::to_string(sql_value.int_value);
		case SqlColumnTypeEnum::SCT_BOOL:
			return sql_value.bool_value ? "1" : "0";
		case SqlColumnTypeEnum::SCT_NVARCHAR:
		case SqlColumnTypeEnum::SCT_STRING:
		case SqlColumnTypeEnum::SCT_TEXT:
		{
			std::string text(sql_value.string_value);
			text = escape_sql_string(text);
			return text;
		} break;
		default:
			throw ChainsqlException(std::string("not supported sql value type ") + std::to_string(sql_value.type));
		}
	}

	std::vector<std::string> RollbackTranslator::generate_rollback_sqls(const SqlChangeInfo &change_info)
	{
		if (!change_info.validate())
		{
			throw ChainsqlException("change info not complete");
		}
		std::vector<std::string> rollback_chainsqls;
		switch (change_info.stmt_type)
		{
		case ChainsqlStmtType::CST_CREATE_TABLE: {
			rollback_chainsqls.push_back(std::string("drop table ") + wrap_table_name(change_info.table_name));
		} break;
		case ChainsqlStmtType::CST_CREATE_INDEX: {
			rollback_chainsqls.push_back(std::string("drop index ") + wrap_table_name(change_info.index_name));
		} break;
		case ChainsqlStmtType::CST_INSERT: {
			rollback_chainsqls.push_back(std::string("delete from ") + wrap_table_name(change_info.table_name) + " where _id=" + std::to_string(change_info.inserted_id));
		} break;
		case ChainsqlStmtType::CST_UPDATE: {
			if (change_info.columns.column_names.empty())
			{
				throw ChainsqlException("update change info structure error when rollback");
			}
			for (const auto &pair : change_info.updated_before_records) {
				std::stringstream ss;
				ss << "update " << wrap_table_name(change_info.table_name) << " set ";
				bool is_first = true;
				for (size_t i = 0; i < change_info.columns.column_names.size(); i++)
				{
					const auto &col_name = change_info.columns.column_names[i];
					if (col_name == "_id")
						continue;
					if (!is_first)
					{
						ss << ",";
					}
					is_first = false;
					if (pair.second.column_values.size() <= i) {
						throw ChainsqlException("column value not found in update sql rollback");
					}
					const auto &col_val = pair.second.column_values[i];
					ss << wrap_column_name(col_name) << "=" << column_value_to_sql(col_val);
				}
				ss << " where _id=" << pair.first;
				const auto &sql = ss.str();
				rollback_chainsqls.push_back(sql);
			}
		} break;
		case ChainsqlStmtType::CST_DELETE: {
			if (change_info.columns.column_names.empty())
			{
				throw ChainsqlException("delete change info structure error when rollback");
			}
			for (const auto &pair : change_info.deleted_before_records) {
				std::stringstream ss;
				ss << "insert into " << wrap_table_name(change_info.table_name) << " (_id";
				int row_id_index = -1;
				for (size_t i = 0; i < change_info.columns.column_names.size(); i++)
				{
					const auto &col_name = change_info.columns.column_names[i];
					if (col_name == "_id")
					{
						row_id_index = i;
						continue;
					}
					ss << "," << wrap_column_name(col_name);
				}
				ss << ") values (" << pair.first;
				if (pair.second.column_values.size() != change_info.columns.column_names.size())
				{
					throw ChainsqlException("delete structure error(columns size error) when rollback");
				}
				for (size_t i = 0; i < pair.second.column_values.size(); i++)
				{
					const auto &col_name = change_info.columns.column_names[i];
					if (row_id_index == i)
						continue;
					const auto &col_val = pair.second.column_values[i];
					ss << "," << column_value_to_sql(col_val);
				}
				ss << ")";
				const auto &sql = ss.str();
				rollback_chainsqls.push_back(sql);
			}
		} break;
		case ChainsqlStmtType::CST_SELECT:
		case ChainsqlStmtType::CST_SHOW_TABLES: {
			// do nothing
		} break;
		default: {
			throw ChainsqlException(std::string("can't rollback chainsql ") + change_info.execute_chainsql);
		}
		}
		return rollback_chainsqls;
	}

	std::string RollbackTranslator::wrap_table_name(std::string chainsql_table_name)
	{
		return _sql_table_prefix + chainsql_table_name;
	}
}
