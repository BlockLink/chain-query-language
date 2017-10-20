// 把chainsql转换成标准SQL语句的转换器visitor

#pragma once

#include <chainsql/chainsql_visitor.h>
#include <vector>
#include <string>

namespace chainsql
{
	class ChainsqlToSqlTranslater : public ChainsqlBaseVisitor
	{
	private:
		std::string _sql_table_prefix; // 要给sql表增加的前缀
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

		// 从update语句生成对应要修改的记录的select语句
		virtual std::string getUpdateStmtAffectSelectStmt(ChainsqlUpdateStmt *stmt);

		// 从delete语句生成对应要修改的记录的select语句
		virtual std::string getDeleteStmtAffectSelectStmt(ChainsqlDeleteStmt *stmt);

	private:
		// 把chainsql中的table name转成目标sql的table name
		std::string wrap_table_name(std::string chainsql_table_name);
	};
}
