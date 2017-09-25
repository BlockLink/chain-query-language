#pragma once

#include <vector>
#include <memory>
#include <chainsql/chainsql_types.h>

namespace chainsql
{
	class ChainsqlContext
	{
	private:
		std::vector<std::unique_ptr<ChainsqlCreateTableStmt>> _managed_create_table_stmts;
		std::vector<std::unique_ptr<ChainsqlCreateIndexStmt>> _managed_create_index_stmts;
		std::vector<std::unique_ptr<ChainsqlDeleteStmt>> _managed_delete_stmts;
		std::vector<std::unique_ptr<ChainsqlInsertStmt>> _managed_insert_stmts;
		std::vector<std::unique_ptr<ChainsqlUpdateStmt>> _managed_update_stmts;
		std::vector<std::unique_ptr<ChainsqlSelectStmt>> _managed_select_stmts;
		std::vector<std::unique_ptr<ChainsqlShowTablesStmt>> _managed_show_tables_stmts;
	public:
		virtual ~ChainsqlContext();

		void add_managed_create_table_stmt(std::unique_ptr<ChainsqlCreateTableStmt> stmt);
		void add_managed_create_index_stmt(std::unique_ptr<ChainsqlCreateIndexStmt> stmt);
		void add_managed_delete_stmt(std::unique_ptr<ChainsqlDeleteStmt> stmt);
		void add_managed_insert_stmt(std::unique_ptr<ChainsqlInsertStmt> stmt);
		void add_managed_update_stmt(std::unique_ptr<ChainsqlUpdateStmt> stmt);
		void add_managed_select_stmt(std::unique_ptr<ChainsqlSelectStmt> stmt);
		void add_managed_show_tables_stmt(std::unique_ptr<ChainsqlShowTablesStmt> stmt);
	};
}
