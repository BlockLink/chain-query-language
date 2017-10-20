// ��chainsqlת���ɱ�׼SQL����ת����visitor

#pragma once

#include <chainsql/chainsql_visitor.h>
#include <vector>
#include <string>

namespace chainsql
{
	class ChainsqlToSqlTranslater : public ChainsqlBaseVisitor
	{
	private:
		std::string _sql_table_prefix; // Ҫ��sql�����ӵ�ǰ׺
		std::vector<std::string> _result_sqls;
	public:
		ChainsqlToSqlTranslater(std::string sql_table_prefix);
		void clear_result_sqls();
		virtual ~ChainsqlToSqlTranslater();
		virtual std::string visitShowTablesStmt(ChainsqlShowTablesStmt *stmt);
		virtual std::string visitCreateTableStmt(ChainsqlCreateTableStmt *stmt);
		virtual std::string visitCreateIndexStmt(ChainsqlCreateIndexStmt *stmt);
		virtual std::string visitInsertStmt(ChainsqlInsertStmt *stmt);
		virtual std::string visitUpdateStmt(ChainsqlUpdateStmt *stmt);
		virtual std::string visitDeleteStmt(ChainsqlDeleteStmt *stmt);
		virtual std::string visitSelectStmt(ChainsqlSelectStmt *stmt);

		// ��update������ɶ�ӦҪ�޸ĵļ�¼��select���
		virtual std::string getUpdateStmtAffectSelectStmt(ChainsqlUpdateStmt *stmt);

		// ��delete������ɶ�ӦҪ�޸ĵļ�¼��select���
		virtual std::string getDeleteStmtAffectSelectStmt(ChainsqlDeleteStmt *stmt);

	private:
		// ��chainsql�е�table nameת��Ŀ��sql��table name
		std::string wrap_table_name(std::string chainsql_table_name);
	};
}
