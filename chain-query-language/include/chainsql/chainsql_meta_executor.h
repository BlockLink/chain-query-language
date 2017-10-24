#pragma once
#include <chainsql/chainsql_types.h>
#include <chainsql/chainsql_visitor.h>
#include <chainsql/chainsql_rollback_translator.h>
#include <memory>

namespace chainsql
{
	class ChainsqlMetaExecutor
	{
	private:
	public:
		ChainsqlMetaExecutor();
		virtual ~ChainsqlMetaExecutor();

		virtual SqlChangeInfo makeShowTablesStmtChange(ChainsqlShowTablesStmt *stmt);
		virtual SqlChangeInfo makeCreateTableStmtChange(ChainsqlCreateTableStmt *stmt);
		virtual SqlChangeInfo makeCreateIndexStmtChange(ChainsqlCreateIndexStmt *stmt);
		virtual SqlChangeInfo makeInsertStmtChange(ChainsqlInsertStmt *stmt, row_id_type inserted_id);
		virtual SqlChangeInfo makeUpdateStmtChange(ChainsqlUpdateStmt *stmt, SqlTableColumns &columns, std::vector<std::pair<row_id_type, SqlRecordData>> &update_before_rows);
		virtual SqlChangeInfo makeDeleteStmtChange(ChainsqlDeleteStmt *stmt, SqlTableColumns &columns, std::vector<std::pair<row_id_type, SqlRecordData>> &delete_before_rows);
		virtual SqlChangeInfo makeSelectStmtChange(ChainsqlSelectStmt *stmt);
	};
}
