
// Generated from E:\projects\chain-query-language\chain-query-language\chainsql.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "chainsql/chainsqlListener.h"


namespace chainsql {

/**
 * This class provides an empty implementation of chainsqlListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  chainsqlBaseListener : public chainsqlListener {
public:

  virtual void enterParse(chainsqlParser::ParseContext * /*ctx*/) override { }
  virtual void exitParse(chainsqlParser::ParseContext * /*ctx*/) override { }

  virtual void enterError(chainsqlParser::ErrorContext * /*ctx*/) override { }
  virtual void exitError(chainsqlParser::ErrorContext * /*ctx*/) override { }

  virtual void enterSql_stmt_list(chainsqlParser::Sql_stmt_listContext * /*ctx*/) override { }
  virtual void exitSql_stmt_list(chainsqlParser::Sql_stmt_listContext * /*ctx*/) override { }

  virtual void enterSql_stmt(chainsqlParser::Sql_stmtContext * /*ctx*/) override { }
  virtual void exitSql_stmt(chainsqlParser::Sql_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_index_stmt(chainsqlParser::Create_index_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_index_stmt(chainsqlParser::Create_index_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_table_stmt(chainsqlParser::Create_table_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_table_stmt(chainsqlParser::Create_table_stmtContext * /*ctx*/) override { }

  virtual void enterDelete_stmt_limited(chainsqlParser::Delete_stmt_limitedContext * /*ctx*/) override { }
  virtual void exitDelete_stmt_limited(chainsqlParser::Delete_stmt_limitedContext * /*ctx*/) override { }

  virtual void enterInsert_stmt(chainsqlParser::Insert_stmtContext * /*ctx*/) override { }
  virtual void exitInsert_stmt(chainsqlParser::Insert_stmtContext * /*ctx*/) override { }

  virtual void enterSelect_stmt(chainsqlParser::Select_stmtContext * /*ctx*/) override { }
  virtual void exitSelect_stmt(chainsqlParser::Select_stmtContext * /*ctx*/) override { }

  virtual void enterUpdate_stmt_limited(chainsqlParser::Update_stmt_limitedContext * /*ctx*/) override { }
  virtual void exitUpdate_stmt_limited(chainsqlParser::Update_stmt_limitedContext * /*ctx*/) override { }

  virtual void enterShow_tables_stmt(chainsqlParser::Show_tables_stmtContext * /*ctx*/) override { }
  virtual void exitShow_tables_stmt(chainsqlParser::Show_tables_stmtContext * /*ctx*/) override { }

  virtual void enterColumn_def(chainsqlParser::Column_defContext * /*ctx*/) override { }
  virtual void exitColumn_def(chainsqlParser::Column_defContext * /*ctx*/) override { }

  virtual void enterType_name(chainsqlParser::Type_nameContext * /*ctx*/) override { }
  virtual void exitType_name(chainsqlParser::Type_nameContext * /*ctx*/) override { }

  virtual void enterExpr(chainsqlParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(chainsqlParser::ExprContext * /*ctx*/) override { }

  virtual void enterIndexed_column(chainsqlParser::Indexed_columnContext * /*ctx*/) override { }
  virtual void exitIndexed_column(chainsqlParser::Indexed_columnContext * /*ctx*/) override { }

  virtual void enterQualified_table_name(chainsqlParser::Qualified_table_nameContext * /*ctx*/) override { }
  virtual void exitQualified_table_name(chainsqlParser::Qualified_table_nameContext * /*ctx*/) override { }

  virtual void enterOrdering_term(chainsqlParser::Ordering_termContext * /*ctx*/) override { }
  virtual void exitOrdering_term(chainsqlParser::Ordering_termContext * /*ctx*/) override { }

  virtual void enterPragma_value(chainsqlParser::Pragma_valueContext * /*ctx*/) override { }
  virtual void exitPragma_value(chainsqlParser::Pragma_valueContext * /*ctx*/) override { }

  virtual void enterCommon_table_expression(chainsqlParser::Common_table_expressionContext * /*ctx*/) override { }
  virtual void exitCommon_table_expression(chainsqlParser::Common_table_expressionContext * /*ctx*/) override { }

  virtual void enterResult_column(chainsqlParser::Result_columnContext * /*ctx*/) override { }
  virtual void exitResult_column(chainsqlParser::Result_columnContext * /*ctx*/) override { }

  virtual void enterTable_or_subquery(chainsqlParser::Table_or_subqueryContext * /*ctx*/) override { }
  virtual void exitTable_or_subquery(chainsqlParser::Table_or_subqueryContext * /*ctx*/) override { }

  virtual void enterSelect_core(chainsqlParser::Select_coreContext * /*ctx*/) override { }
  virtual void exitSelect_core(chainsqlParser::Select_coreContext * /*ctx*/) override { }

  virtual void enterCte_table_name(chainsqlParser::Cte_table_nameContext * /*ctx*/) override { }
  virtual void exitCte_table_name(chainsqlParser::Cte_table_nameContext * /*ctx*/) override { }

  virtual void enterSigned_number(chainsqlParser::Signed_numberContext * /*ctx*/) override { }
  virtual void exitSigned_number(chainsqlParser::Signed_numberContext * /*ctx*/) override { }

  virtual void enterLiteral_value(chainsqlParser::Literal_valueContext * /*ctx*/) override { }
  virtual void exitLiteral_value(chainsqlParser::Literal_valueContext * /*ctx*/) override { }

  virtual void enterError_message(chainsqlParser::Error_messageContext * /*ctx*/) override { }
  virtual void exitError_message(chainsqlParser::Error_messageContext * /*ctx*/) override { }

  virtual void enterModule_argument(chainsqlParser::Module_argumentContext * /*ctx*/) override { }
  virtual void exitModule_argument(chainsqlParser::Module_argumentContext * /*ctx*/) override { }

  virtual void enterColumn_alias(chainsqlParser::Column_aliasContext * /*ctx*/) override { }
  virtual void exitColumn_alias(chainsqlParser::Column_aliasContext * /*ctx*/) override { }

  virtual void enterKeyword(chainsqlParser::KeywordContext * /*ctx*/) override { }
  virtual void exitKeyword(chainsqlParser::KeywordContext * /*ctx*/) override { }

  virtual void enterName(chainsqlParser::NameContext * /*ctx*/) override { }
  virtual void exitName(chainsqlParser::NameContext * /*ctx*/) override { }

  virtual void enterFunction_name(chainsqlParser::Function_nameContext * /*ctx*/) override { }
  virtual void exitFunction_name(chainsqlParser::Function_nameContext * /*ctx*/) override { }

  virtual void enterTable_name(chainsqlParser::Table_nameContext * /*ctx*/) override { }
  virtual void exitTable_name(chainsqlParser::Table_nameContext * /*ctx*/) override { }

  virtual void enterTable_or_index_name(chainsqlParser::Table_or_index_nameContext * /*ctx*/) override { }
  virtual void exitTable_or_index_name(chainsqlParser::Table_or_index_nameContext * /*ctx*/) override { }

  virtual void enterNew_table_name(chainsqlParser::New_table_nameContext * /*ctx*/) override { }
  virtual void exitNew_table_name(chainsqlParser::New_table_nameContext * /*ctx*/) override { }

  virtual void enterColumn_name(chainsqlParser::Column_nameContext * /*ctx*/) override { }
  virtual void exitColumn_name(chainsqlParser::Column_nameContext * /*ctx*/) override { }

  virtual void enterCollation_name(chainsqlParser::Collation_nameContext * /*ctx*/) override { }
  virtual void exitCollation_name(chainsqlParser::Collation_nameContext * /*ctx*/) override { }

  virtual void enterForeign_table(chainsqlParser::Foreign_tableContext * /*ctx*/) override { }
  virtual void exitForeign_table(chainsqlParser::Foreign_tableContext * /*ctx*/) override { }

  virtual void enterIndex_name(chainsqlParser::Index_nameContext * /*ctx*/) override { }
  virtual void exitIndex_name(chainsqlParser::Index_nameContext * /*ctx*/) override { }

  virtual void enterTrigger_name(chainsqlParser::Trigger_nameContext * /*ctx*/) override { }
  virtual void exitTrigger_name(chainsqlParser::Trigger_nameContext * /*ctx*/) override { }

  virtual void enterView_name(chainsqlParser::View_nameContext * /*ctx*/) override { }
  virtual void exitView_name(chainsqlParser::View_nameContext * /*ctx*/) override { }

  virtual void enterModule_name(chainsqlParser::Module_nameContext * /*ctx*/) override { }
  virtual void exitModule_name(chainsqlParser::Module_nameContext * /*ctx*/) override { }

  virtual void enterPragma_name(chainsqlParser::Pragma_nameContext * /*ctx*/) override { }
  virtual void exitPragma_name(chainsqlParser::Pragma_nameContext * /*ctx*/) override { }

  virtual void enterSavepoint_name(chainsqlParser::Savepoint_nameContext * /*ctx*/) override { }
  virtual void exitSavepoint_name(chainsqlParser::Savepoint_nameContext * /*ctx*/) override { }

  virtual void enterTable_alias(chainsqlParser::Table_aliasContext * /*ctx*/) override { }
  virtual void exitTable_alias(chainsqlParser::Table_aliasContext * /*ctx*/) override { }

  virtual void enterTransaction_name(chainsqlParser::Transaction_nameContext * /*ctx*/) override { }
  virtual void exitTransaction_name(chainsqlParser::Transaction_nameContext * /*ctx*/) override { }

  virtual void enterAny_name(chainsqlParser::Any_nameContext * /*ctx*/) override { }
  virtual void exitAny_name(chainsqlParser::Any_nameContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace chainsql
