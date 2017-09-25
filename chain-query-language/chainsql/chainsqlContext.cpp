#include <chainsql/chainsqlContext.h>

namespace chainsql
{
	ChainsqlContext::~ChainsqlContext()
	{

	}
	void ChainsqlContext::add_managed_create_table_stmt(std::unique_ptr<ChainsqlCreateTableStmt> stmt)
	{
		_managed_create_table_stmts.push_back(std::move(stmt));
	}

	void ChainsqlContext::add_managed_create_index_stmt(std::unique_ptr<ChainsqlCreateIndexStmt> stmt)
	{
		_managed_create_index_stmts.push_back(std::move(stmt));
	}

	void ChainsqlContext::add_managed_delete_stmt(std::unique_ptr<ChainsqlDeleteStmt> stmt)
	{
		_managed_delete_stmts.push_back(std::move(stmt));
	}
	void ChainsqlContext::add_managed_insert_stmt(std::unique_ptr<ChainsqlInsertStmt> stmt)
	{
		_managed_insert_stmts.push_back(std::move(stmt));
	}
	void ChainsqlContext::add_managed_update_stmt(std::unique_ptr<ChainsqlUpdateStmt> stmt)
	{
		_managed_update_stmts.push_back(std::move(stmt));
	}
	void ChainsqlContext::add_managed_select_stmt(std::unique_ptr<ChainsqlSelectStmt> stmt)
	{
		_managed_select_stmts.push_back(std::move(stmt));
	}
	void ChainsqlContext::add_managed_show_tables_stmt(std::unique_ptr<ChainsqlShowTablesStmt> stmt)
	{
		_managed_show_tables_stmts.push_back(std::move(stmt));
	}

}
