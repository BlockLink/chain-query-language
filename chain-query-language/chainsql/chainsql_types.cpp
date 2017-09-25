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

}
