#include <chainsql/chainsql_meta_executor.h>
#include <boost/algorithm/string.hpp>

namespace chainsql
{
	ChainsqlMetaExecutor::ChainsqlMetaExecutor()
	{
	}

	ChainsqlMetaExecutor::~ChainsqlMetaExecutor()
	{

	}

	SqlChangeInfo ChainsqlMetaExecutor::makeShowTablesStmtChange(ChainsqlShowTablesStmt *stmt)
	{
		SqlChangeInfo change_info;
		change_info.stmt_type = stmt->stmt_type();
		return change_info;
	}
	SqlChangeInfo ChainsqlMetaExecutor::makeCreateTableStmtChange(ChainsqlCreateTableStmt *stmt)
	{
		SqlChangeInfo change_info;
		change_info.stmt_type = stmt->stmt_type();
		change_info.table_name = stmt->table_name();
		return change_info;
	}
	SqlChangeInfo ChainsqlMetaExecutor::makeCreateIndexStmtChange(ChainsqlCreateIndexStmt *stmt)
	{
		SqlChangeInfo change_info;
		change_info.stmt_type = stmt->stmt_type();
		change_info.index_name = stmt->index_name;
		return change_info;
	}
	SqlChangeInfo ChainsqlMetaExecutor::makeInsertStmtChange(ChainsqlInsertStmt *stmt, row_id_type inserted_id)
	{
		SqlChangeInfo change_info;
		change_info.stmt_type = stmt->stmt_type();
		change_info.table_name = stmt->table_name();
		change_info.inserted_id = inserted_id;
		return change_info;
	}
	SqlChangeInfo ChainsqlMetaExecutor::makeUpdateStmtChange(ChainsqlUpdateStmt *stmt, SqlTableColumns &columns, std::vector<std::pair<row_id_type, SqlRecordData>> &update_before_rows)
	{
		SqlChangeInfo change_info;
		change_info.stmt_type = stmt->stmt_type();
		change_info.table_name = stmt->table_name;
		change_info.columns = columns;
		change_info.updated_before_records = update_before_rows;
		return change_info;
	}
	SqlChangeInfo ChainsqlMetaExecutor::makeDeleteStmtChange(ChainsqlDeleteStmt *stmt, SqlTableColumns &columns, std::vector<std::pair<row_id_type, SqlRecordData>> &delete_before_rows)
	{
		SqlChangeInfo change_info;
		change_info.stmt_type = stmt->stmt_type();
		change_info.table_name = stmt->table_name;
		change_info.columns = columns;
		change_info.deleted_before_records = delete_before_rows;
		return change_info;
	}
	SqlChangeInfo ChainsqlMetaExecutor::makeSelectStmtChange(ChainsqlSelectStmt *stmt)
	{
		SqlChangeInfo change_info;
		change_info.stmt_type = stmt->stmt_type();
		return change_info;
	}


}
