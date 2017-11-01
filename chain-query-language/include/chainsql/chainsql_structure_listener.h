// ��antlr���ɵĽṹת���ɸ�����ʹ�õĽṹ

#pragma once
#include <antlr4-runtime.h>
#include <chainsql/chainsqlBaseListener.h>
#include <chainsql/chainsql_types.h>
#include <chainsql/chainsqlContext.h>

#include <vector>
#include <string>
#include <functional>
#include <memory>

namespace chainsql
{
	using namespace antlr4;
	using namespace antlr4::tree;

	class chainsqlStructureListener : public chainsqlBaseListener {
	private:
		std::vector<ChainsqlStmt*> _chainsql_stmts;

		ChainsqlContext _chainsql_ctx;

		std::vector<ChainsqlColumnDef> _tmp_column_defs; // ��ʱ��column_def���������ϼ����ݽṹ��ʹ��
		ChainsqlSelectStmt _tmp_select_info; // ��ʱ��select���Ĳ��ֽṹ,�������ϼ����ݽṹ��ʹ��


	public:
		virtual ~chainsqlStructureListener();

		std::vector<ChainsqlStmt*> chainsql_stmts() const;
	public:
		virtual void enterParse(chainsqlParser::ParseContext * /*ctx*/) override;
		virtual void exitParse(chainsqlParser::ParseContext * /*ctx*/) override;

		virtual void enterError(chainsqlParser::ErrorContext * /*ctx*/) override;
		virtual void exitError(chainsqlParser::ErrorContext * /*ctx*/) override;

		virtual void enterSql_stmt_list(chainsqlParser::Sql_stmt_listContext * /*ctx*/) override;
		virtual void exitSql_stmt_list(chainsqlParser::Sql_stmt_listContext * /*ctx*/) override;

		virtual void enterSql_stmt(chainsqlParser::Sql_stmtContext * /*ctx*/) override;
		virtual void exitSql_stmt(chainsqlParser::Sql_stmtContext * /*ctx*/) override;

		virtual void enterCreate_table_stmt(chainsqlParser::Create_table_stmtContext * /*ctx*/) override;
		virtual void exitCreate_table_stmt(chainsqlParser::Create_table_stmtContext * /*ctx*/) override;

		virtual void enterCreate_index_stmt(chainsqlParser::Create_index_stmtContext * /*ctx*/) override;
		virtual void exitCreate_index_stmt(chainsqlParser::Create_index_stmtContext * /*ctx*/) override;

		virtual void enterDelete_stmt_limited(chainsqlParser::Delete_stmt_limitedContext * /*ctx*/) override;
		virtual void exitDelete_stmt_limited(chainsqlParser::Delete_stmt_limitedContext * /*ctx*/) override;

		virtual void enterInsert_stmt(chainsqlParser::Insert_stmtContext * /*ctx*/) override;
		virtual void exitInsert_stmt(chainsqlParser::Insert_stmtContext * /*ctx*/) override;

		virtual void enterSelect_stmt(chainsqlParser::Select_stmtContext * /*ctx*/) override;
		virtual void exitSelect_stmt(chainsqlParser::Select_stmtContext * /*ctx*/) override;

		virtual void enterUpdate_stmt_limited(chainsqlParser::Update_stmt_limitedContext * /*ctx*/) override;
		virtual void exitUpdate_stmt_limited(chainsqlParser::Update_stmt_limitedContext * /*ctx*/) override;

		virtual void enterColumn_def(chainsqlParser::Column_defContext * /*ctx*/) override;
		virtual void exitColumn_def(chainsqlParser::Column_defContext * /*ctx*/) override;

		virtual void enterShow_tables_stmt(chainsqlParser::Show_tables_stmtContext * /*ctx*/) override;
		virtual void exitShow_tables_stmt(chainsqlParser::Show_tables_stmtContext * /*ctx*/) override;

		virtual void enterExpr(chainsqlParser::ExprContext * /*ctx*/) override;
		virtual void exitExpr(chainsqlParser::ExprContext * /*ctx*/) override;

		virtual void enterType_name(chainsqlParser::Type_nameContext * /*ctx*/) override;
		virtual void exitType_name(chainsqlParser::Type_nameContext * /*ctx*/) override;

		virtual void enterColumn_name(chainsqlParser::Column_nameContext * /*ctx*/) override;
		virtual void exitColumn_name(chainsqlParser::Column_nameContext * /*ctx*/) override;

	};
}