#include <chainsql/chainsql_types.h>
#include <chainsql/chainsql_visitor.h>

namespace chainsql
{
	ChainsqlStmt::~ChainsqlStmt()
	{

	}

	void ChainsqlCreateTableStmt::set_table_name(std::string table_name)
	{
		this->_table_name = table_name;
	}

	void ChainsqlCreateTableStmt::add_column_defs(std::vector<ChainsqlColumnDef> &column_defs)
	{
		for (const auto &item : column_defs)
		{
			_column_defs.push_back(item);
		}
	}
	void ChainsqlCreateTableStmt::add_column_def(ChainsqlColumnDef column_def)
	{
		_column_defs.push_back(column_def);
	}

	void ChainsqlInsertStmt::set_table_name(std::string table_name)
	{
		this->_table_name = table_name;
	}
	void ChainsqlInsertStmt::add_column_name(std::string column_name)
	{
		_column_names.push_back(column_name);
	}
	void ChainsqlInsertStmt::add_column_value(ChainsqlExpr value_tokens)
	{
		_column_values.push_back(value_tokens);
	}

	ChainsqlSelectStmt::ChainsqlSelectStmt()
	{
		limit = 0;
		offset = 0;
		distinct = false;
		all = false;
	}

	std::string ChainsqlCreateTableStmt::accept(ChainsqlBaseVisitor *visitor)
	{
		return visitor->visitCreateTableStmt(this);
	}

	std::string ChainsqlCreateIndexStmt::accept(ChainsqlBaseVisitor *visitor)
	{
		return visitor->visitCreateIndexStmt(this);
	}
	std::string ChainsqlShowTablesStmt::accept(ChainsqlBaseVisitor *visitor)
	{
		return visitor->visitShowTablesStmt(this);
	}
	std::string ChainsqlInsertStmt::accept(ChainsqlBaseVisitor *visitor)
	{
		return visitor->visitInsertStmt(this);
	}
	std::string ChainsqlUpdateStmt::accept(ChainsqlBaseVisitor *visitor)
	{
		return visitor->visitUpdateStmt(this);
	}
	std::string ChainsqlDeleteStmt::accept(ChainsqlBaseVisitor *visitor)
	{
		return visitor->visitDeleteStmt(this);
	}
	std::string ChainsqlSelectStmt::accept(ChainsqlBaseVisitor *visitor)
	{
		return visitor->visitSelectStmt(this);
	}

	SqlChangeInfo::SqlChangeInfo()
		: inserted_id(0), stmt_type(ChainsqlStmtType::CST_SELECT)
	{

	}

	bool SqlChangeInfo::validate() const
	{
		switch (stmt_type)
		{
		case ChainsqlStmtType::CST_CREATE_INDEX:
			return !index_name.empty();
		case ChainsqlStmtType::CST_CREATE_TABLE:
			return !table_name.empty();
		case ChainsqlStmtType::CST_SELECT:
			return true;
		case ChainsqlStmtType::CST_SHOW_TABLES:
			return true;
		case ChainsqlStmtType::CST_INSERT:
			return table_name.size() > 0 && inserted_id > 0;
		case ChainsqlStmtType::CST_UPDATE:
		{
			if (table_name.empty() || columns.column_names.empty() || updated_before_records.empty())
				return false;
			auto columns_count = columns.column_names.size();
			for (const auto &pair : updated_before_records)
			{
				if (pair.first <= 0)
					return false;
				if (pair.second.column_values.size() != columns_count)
					return false;
			}
			return true;
		}
		case ChainsqlStmtType::CST_DELETE:
		{
			if (table_name.empty() || columns.column_names.empty() || deleted_before_records.empty())
				return false;
			auto columns_count = columns.column_names.size();
			for (const auto &pair : deleted_before_records)
			{
				if (pair.first <= 0)
					return false;
				if (pair.second.column_values.size() != columns_count)
					return false;
			}
			return true;
		}
		}
		return true;
	}

	SqlValue SqlValue::create_null()
	{
		SqlValue sql_value;
		sql_value.is_null = true;
		return sql_value;
	}
	SqlValue SqlValue::create_int(int64_t value)
	{
		SqlValue sql_value(SqlColumnTypeEnum::SCT_INT);
		sql_value.int_value = value;
		return sql_value;
	}
	SqlValue SqlValue::create_bigint(int64_t value)
	{
		SqlValue sql_value(SqlColumnTypeEnum::SCT_BIGINT);
		sql_value.int_value = value;
		return sql_value;
	}
	SqlValue SqlValue::create_string(const std::string &value)
	{
		SqlValue sql_value(SqlColumnTypeEnum::SCT_STRING);
		sql_value.string_value = value;
		return sql_value;
	}
	SqlValue SqlValue::create_varchar(const std::string &value)
	{
		SqlValue sql_value(SqlColumnTypeEnum::SCT_NVARCHAR);
		sql_value.string_value = value;
		return sql_value;
	}
	SqlValue SqlValue::create_text(const std::string &value)
	{
		SqlValue sql_value(SqlColumnTypeEnum::SCT_TEXT);
		sql_value.string_value = value;
		return sql_value;
	}
	SqlValue SqlValue::create_bool(bool value)
	{
		SqlValue sql_value(SqlColumnTypeEnum::SCT_BOOL);
		sql_value.bool_value = value;
		return sql_value;
	}

}
