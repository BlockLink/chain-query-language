
// Generated from E:\projects\chain-query-language\chain-query-language\chainsql.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "chainsql/chainsqlParser.h"


namespace chainsql {

/**
 * This interface defines an abstract listener for a parse tree produced by chainsqlParser.
 */
class  chainsqlListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterParse(chainsqlParser::ParseContext *ctx) = 0;
  virtual void exitParse(chainsqlParser::ParseContext *ctx) = 0;

  virtual void enterError(chainsqlParser::ErrorContext *ctx) = 0;
  virtual void exitError(chainsqlParser::ErrorContext *ctx) = 0;

  virtual void enterSql_stmt_list(chainsqlParser::Sql_stmt_listContext *ctx) = 0;
  virtual void exitSql_stmt_list(chainsqlParser::Sql_stmt_listContext *ctx) = 0;

  virtual void enterSql_stmt(chainsqlParser::Sql_stmtContext *ctx) = 0;
  virtual void exitSql_stmt(chainsqlParser::Sql_stmtContext *ctx) = 0;

  virtual void enterCreate_index_stmt(chainsqlParser::Create_index_stmtContext *ctx) = 0;
  virtual void exitCreate_index_stmt(chainsqlParser::Create_index_stmtContext *ctx) = 0;

  virtual void enterCreate_table_stmt(chainsqlParser::Create_table_stmtContext *ctx) = 0;
  virtual void exitCreate_table_stmt(chainsqlParser::Create_table_stmtContext *ctx) = 0;

  virtual void enterDelete_stmt_limited(chainsqlParser::Delete_stmt_limitedContext *ctx) = 0;
  virtual void exitDelete_stmt_limited(chainsqlParser::Delete_stmt_limitedContext *ctx) = 0;

  virtual void enterInsert_stmt(chainsqlParser::Insert_stmtContext *ctx) = 0;
  virtual void exitInsert_stmt(chainsqlParser::Insert_stmtContext *ctx) = 0;

  virtual void enterSelect_stmt(chainsqlParser::Select_stmtContext *ctx) = 0;
  virtual void exitSelect_stmt(chainsqlParser::Select_stmtContext *ctx) = 0;

  virtual void enterUpdate_stmt_limited(chainsqlParser::Update_stmt_limitedContext *ctx) = 0;
  virtual void exitUpdate_stmt_limited(chainsqlParser::Update_stmt_limitedContext *ctx) = 0;

  virtual void enterShow_tables_stmt(chainsqlParser::Show_tables_stmtContext *ctx) = 0;
  virtual void exitShow_tables_stmt(chainsqlParser::Show_tables_stmtContext *ctx) = 0;

  virtual void enterColumn_def(chainsqlParser::Column_defContext *ctx) = 0;
  virtual void exitColumn_def(chainsqlParser::Column_defContext *ctx) = 0;

  virtual void enterType_name(chainsqlParser::Type_nameContext *ctx) = 0;
  virtual void exitType_name(chainsqlParser::Type_nameContext *ctx) = 0;

  virtual void enterExpr(chainsqlParser::ExprContext *ctx) = 0;
  virtual void exitExpr(chainsqlParser::ExprContext *ctx) = 0;

  virtual void enterIndexed_column(chainsqlParser::Indexed_columnContext *ctx) = 0;
  virtual void exitIndexed_column(chainsqlParser::Indexed_columnContext *ctx) = 0;

  virtual void enterQualified_table_name(chainsqlParser::Qualified_table_nameContext *ctx) = 0;
  virtual void exitQualified_table_name(chainsqlParser::Qualified_table_nameContext *ctx) = 0;

  virtual void enterOrdering_term(chainsqlParser::Ordering_termContext *ctx) = 0;
  virtual void exitOrdering_term(chainsqlParser::Ordering_termContext *ctx) = 0;

  virtual void enterPragma_value(chainsqlParser::Pragma_valueContext *ctx) = 0;
  virtual void exitPragma_value(chainsqlParser::Pragma_valueContext *ctx) = 0;

  virtual void enterCommon_table_expression(chainsqlParser::Common_table_expressionContext *ctx) = 0;
  virtual void exitCommon_table_expression(chainsqlParser::Common_table_expressionContext *ctx) = 0;

  virtual void enterResult_column(chainsqlParser::Result_columnContext *ctx) = 0;
  virtual void exitResult_column(chainsqlParser::Result_columnContext *ctx) = 0;

  virtual void enterTable_or_subquery(chainsqlParser::Table_or_subqueryContext *ctx) = 0;
  virtual void exitTable_or_subquery(chainsqlParser::Table_or_subqueryContext *ctx) = 0;

  virtual void enterSelect_core(chainsqlParser::Select_coreContext *ctx) = 0;
  virtual void exitSelect_core(chainsqlParser::Select_coreContext *ctx) = 0;

  virtual void enterCte_table_name(chainsqlParser::Cte_table_nameContext *ctx) = 0;
  virtual void exitCte_table_name(chainsqlParser::Cte_table_nameContext *ctx) = 0;

  virtual void enterSigned_number(chainsqlParser::Signed_numberContext *ctx) = 0;
  virtual void exitSigned_number(chainsqlParser::Signed_numberContext *ctx) = 0;

  virtual void enterLiteral_value(chainsqlParser::Literal_valueContext *ctx) = 0;
  virtual void exitLiteral_value(chainsqlParser::Literal_valueContext *ctx) = 0;

  virtual void enterError_message(chainsqlParser::Error_messageContext *ctx) = 0;
  virtual void exitError_message(chainsqlParser::Error_messageContext *ctx) = 0;

  virtual void enterModule_argument(chainsqlParser::Module_argumentContext *ctx) = 0;
  virtual void exitModule_argument(chainsqlParser::Module_argumentContext *ctx) = 0;

  virtual void enterColumn_alias(chainsqlParser::Column_aliasContext *ctx) = 0;
  virtual void exitColumn_alias(chainsqlParser::Column_aliasContext *ctx) = 0;

  virtual void enterKeyword(chainsqlParser::KeywordContext *ctx) = 0;
  virtual void exitKeyword(chainsqlParser::KeywordContext *ctx) = 0;

  virtual void enterName(chainsqlParser::NameContext *ctx) = 0;
  virtual void exitName(chainsqlParser::NameContext *ctx) = 0;

  virtual void enterFunction_name(chainsqlParser::Function_nameContext *ctx) = 0;
  virtual void exitFunction_name(chainsqlParser::Function_nameContext *ctx) = 0;

  virtual void enterTable_name(chainsqlParser::Table_nameContext *ctx) = 0;
  virtual void exitTable_name(chainsqlParser::Table_nameContext *ctx) = 0;

  virtual void enterTable_or_index_name(chainsqlParser::Table_or_index_nameContext *ctx) = 0;
  virtual void exitTable_or_index_name(chainsqlParser::Table_or_index_nameContext *ctx) = 0;

  virtual void enterNew_table_name(chainsqlParser::New_table_nameContext *ctx) = 0;
  virtual void exitNew_table_name(chainsqlParser::New_table_nameContext *ctx) = 0;

  virtual void enterColumn_name(chainsqlParser::Column_nameContext *ctx) = 0;
  virtual void exitColumn_name(chainsqlParser::Column_nameContext *ctx) = 0;

  virtual void enterCollation_name(chainsqlParser::Collation_nameContext *ctx) = 0;
  virtual void exitCollation_name(chainsqlParser::Collation_nameContext *ctx) = 0;

  virtual void enterForeign_table(chainsqlParser::Foreign_tableContext *ctx) = 0;
  virtual void exitForeign_table(chainsqlParser::Foreign_tableContext *ctx) = 0;

  virtual void enterIndex_name(chainsqlParser::Index_nameContext *ctx) = 0;
  virtual void exitIndex_name(chainsqlParser::Index_nameContext *ctx) = 0;

  virtual void enterTrigger_name(chainsqlParser::Trigger_nameContext *ctx) = 0;
  virtual void exitTrigger_name(chainsqlParser::Trigger_nameContext *ctx) = 0;

  virtual void enterView_name(chainsqlParser::View_nameContext *ctx) = 0;
  virtual void exitView_name(chainsqlParser::View_nameContext *ctx) = 0;

  virtual void enterModule_name(chainsqlParser::Module_nameContext *ctx) = 0;
  virtual void exitModule_name(chainsqlParser::Module_nameContext *ctx) = 0;

  virtual void enterPragma_name(chainsqlParser::Pragma_nameContext *ctx) = 0;
  virtual void exitPragma_name(chainsqlParser::Pragma_nameContext *ctx) = 0;

  virtual void enterSavepoint_name(chainsqlParser::Savepoint_nameContext *ctx) = 0;
  virtual void exitSavepoint_name(chainsqlParser::Savepoint_nameContext *ctx) = 0;

  virtual void enterTable_alias(chainsqlParser::Table_aliasContext *ctx) = 0;
  virtual void exitTable_alias(chainsqlParser::Table_aliasContext *ctx) = 0;

  virtual void enterTransaction_name(chainsqlParser::Transaction_nameContext *ctx) = 0;
  virtual void exitTransaction_name(chainsqlParser::Transaction_nameContext *ctx) = 0;

  virtual void enterAny_name(chainsqlParser::Any_nameContext *ctx) = 0;
  virtual void exitAny_name(chainsqlParser::Any_nameContext *ctx) = 0;


};

}  // namespace chainsql
