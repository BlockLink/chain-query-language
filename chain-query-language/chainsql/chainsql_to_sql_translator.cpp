#include <chainsql/chainsql_to_sql_translator.h>
#include <chainsql/utils.h>

#include <sstream>

namespace chainsql
{
	ChainsqlToSqlTranslater::ChainsqlToSqlTranslater(std::string sql_table_prefix)
	{
		_sql_table_prefix = sql_table_prefix;
	}
	ChainsqlToSqlTranslater::~ChainsqlToSqlTranslater()
	{

	}
	void ChainsqlToSqlTranslater::clear_result_sqls()
	{
		_result_sqls.clear();
	}

	std::string ChainsqlToSqlTranslater::wrap_table_name(std::string chainsql_table_name)
	{
		return _sql_table_prefix + chainsql_table_name;
	}

	std::string ChainsqlToSqlTranslater::visitShowTablesStmt(ChainsqlShowTablesStmt *stmt)
	{
		std::string sql("show tables");
		_result_sqls.push_back(sql);
		return sql;
	}
	std::string ChainsqlToSqlTranslater::visitCreateTableStmt(ChainsqlCreateTableStmt *stmt)
	{
		std::stringstream sql_ss;
		sql_ss << "create table " << wrap_table_name(stmt->table_name()) << " ";
		sql_ss << "(";
		const auto &column_defs = stmt->column_defs();
		for (size_t i=0;i<column_defs.size();i++)
		{
			if (i > 0)
				sql_ss << ",";
			const auto &col = column_defs[i];
			sql_ss << col.column_name << " " << col.column_type;
		}
		sql_ss << ")";
		auto sql = sql_ss.str();
		_result_sqls.push_back(sql);
		return sql;
	}
	std::string ChainsqlToSqlTranslater::visitCreateIndexStmt(ChainsqlCreateIndexStmt *stmt)
	{
		std::stringstream sql_ss;
		sql_ss << "create ";
		if (stmt->unique)
			sql_ss << "unique ";
		sql_ss << "index " << wrap_table_name(stmt->index_name) << " on " << wrap_table_name(stmt->table_name) << " ";
		sql_ss << "(";
		const auto &columns = stmt->column_names;
		for (size_t i = 0; i < columns.size(); i++)
		{
			if (i > 0)
				sql_ss << ",";
			const auto &col = columns[i];
			sql_ss << col.first << " " << (col.second ? "asc" : "desc");
		}
		sql_ss << ")";
		auto sql = sql_ss.str();
		_result_sqls.push_back(sql);
		return sql;
	}
	std::string ChainsqlToSqlTranslater::visitInsertStmt(ChainsqlInsertStmt *stmt)
	{
		std::stringstream sql_ss;
		sql_ss << "insert into " << wrap_table_name(stmt->table_name()) << " ";
		sql_ss << "(";
		// column names
		const auto &column_names = stmt->column_names();
		for (size_t i = 0; i < column_names.size(); i++)
		{
			if (i > 0)
				sql_ss << ",";
			sql_ss << column_names[i];
		}
		sql_ss << ")";
		sql_ss << " values ";
		sql_ss << "(";
		// column values
		const auto &column_values = stmt->column_values();
		for (size_t i = 0; i < column_values.size(); i++)
		{
			if (i > 0)
				sql_ss << ",";
			const auto &col_value = column_values[i];
			sql_ss << utils::vector_join(col_value.tokens, " ");
		}
		sql_ss << ")";

		auto sql = sql_ss.str();
		_result_sqls.push_back(sql);
		return sql;
	}
	std::string ChainsqlToSqlTranslater::visitUpdateStmt(ChainsqlUpdateStmt *stmt)
	{
		std::stringstream sql_ss;
		sql_ss << "update " << wrap_table_name(stmt->table_name) << " set ";
		const auto &set_columns = stmt->set_columns;
		for (size_t i = 0; i < set_columns.size(); i++)
		{
			const auto &set_column = set_columns[i];
			sql_ss << set_column.first << "=" << utils::vector_join(set_column.second.tokens, " ");
		}
		if (stmt->condition)
		{
			sql_ss << " where ";
			sql_ss << utils::vector_join(stmt->condition->tokens, " ");
		}
		if (stmt->orders.size() > 0)
		{
			sql_ss << " order by ";
			const auto &orders = stmt->orders;
			for (size_t i = 0; i < orders.size(); i++)
			{
				if (i > 0)
					sql_ss << ",";
				const auto &order = orders[i];
				sql_ss << order.column_name << " " << (order.ascending ? "asc" : "desc");
			}
		}
		sql_ss << " limit " << stmt->limit;
		auto sql = sql_ss.str();
		_result_sqls.push_back(sql);
		return sql;
	}
	std::string ChainsqlToSqlTranslater::visitDeleteStmt(ChainsqlDeleteStmt *stmt)
	{
		std::stringstream sql_ss;
		sql_ss << "delete from " << wrap_table_name(stmt->table_name);
		if (stmt->condition)
		{
			sql_ss << " where ";
			sql_ss << utils::vector_join(stmt->condition->tokens, " ");
		}
		if (stmt->orders.size() > 0)
		{
			sql_ss << " order by ";
			const auto &orders = stmt->orders;
			for (size_t i = 0; i < orders.size(); i++)
			{
				if (i > 0)
					sql_ss << ",";
				const auto &order = orders[i];
				sql_ss << order.column_name << " " << (order.ascending ? "asc" : "desc");
			}
		}
		sql_ss << " limit " << stmt->limit;
		auto sql = sql_ss.str();
		_result_sqls.push_back(sql);
		return sql;
	}
	std::string ChainsqlToSqlTranslater::visitSelectStmt(ChainsqlSelectStmt *stmt)
	{
		std::stringstream sql_ss;
		sql_ss << "select";
		if (stmt->distinct)
			sql_ss << " distinct";
		else if (stmt->all)
			sql_ss << " all";
		sql_ss << " ";
		// result columns
		const auto& result_columns = stmt->result_columns;
		for (size_t i = 0; i < result_columns.size(); i++)
		{
			if (i > 0)
				sql_ss << ",";
			const auto &result_col = result_columns[i];
			sql_ss << utils::vector_join(result_col.tokens, " ");
		}
		sql_ss << " from ";
		const auto &tables = stmt->tables;
		for (size_t i = 0; i < tables.size(); i++)
		{
			if (i > 0)
				sql_ss << ",";
			const auto &table = tables[i];
			sql_ss << wrap_table_name(table.table_name);
			if (!table.alias.empty())
			{
				sql_ss << " as " << table.alias;
			}
		}
		if (stmt->condition)
		{
			sql_ss << " where ";
			sql_ss << utils::vector_join(stmt->condition->tokens, " ");
		}
		if (stmt->group_by)
		{
			sql_ss << " group by ";
			const auto &group_by_items = stmt->group_by->exprs;
			for (size_t i = 0; i < group_by_items.size(); i++)
			{
				if (i > 0)
					sql_ss << ",";
				const auto &item = group_by_items[i];
				sql_ss << utils::vector_join(item.tokens, " ");
			}
			if (stmt->group_by->having_expr)
			{
				sql_ss << " having ";
				const auto &having_items = stmt->group_by->having_expr;
				sql_ss << utils::vector_join(having_items->tokens, " ");
			}
		}
		if (stmt->orders.size() > 0)
		{
			sql_ss << " order by ";
			const auto &orders = stmt->orders;
			for (size_t i = 0; i < orders.size(); i++)
			{
				if (i > 0)
					sql_ss << ",";
				const auto &order = orders[i];
				sql_ss << order.column_name << " " << (order.ascending ? "asc" : "desc");
			}
		}
		sql_ss << " limit " << stmt->limit << " offset " << stmt->offset;
		auto sql = sql_ss.str();
		_result_sqls.push_back(sql);
		return sql;
	}

}
