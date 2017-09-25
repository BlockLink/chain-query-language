
// Generated from E:\projects\chain-query-language\chain-query-language\chainsql.g4 by ANTLR 4.7


#include "chainsql/chainsqlListener.h"

#include "chainsql/chainsqlParser.h"


using namespace antlrcpp;
using namespace chainsql;
using namespace antlr4;

chainsqlParser::chainsqlParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

chainsqlParser::~chainsqlParser() {
  delete _interpreter;
}

std::string chainsqlParser::getGrammarFileName() const {
  return "chainsql.g4";
}

const std::vector<std::string>& chainsqlParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& chainsqlParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ParseContext ------------------------------------------------------------------

chainsqlParser::ParseContext::ParseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::ParseContext::EOF() {
  return getToken(chainsqlParser::EOF, 0);
}

std::vector<chainsqlParser::Sql_stmt_listContext *> chainsqlParser::ParseContext::sql_stmt_list() {
  return getRuleContexts<chainsqlParser::Sql_stmt_listContext>();
}

chainsqlParser::Sql_stmt_listContext* chainsqlParser::ParseContext::sql_stmt_list(size_t i) {
  return getRuleContext<chainsqlParser::Sql_stmt_listContext>(i);
}

std::vector<chainsqlParser::ErrorContext *> chainsqlParser::ParseContext::error() {
  return getRuleContexts<chainsqlParser::ErrorContext>();
}

chainsqlParser::ErrorContext* chainsqlParser::ParseContext::error(size_t i) {
  return getRuleContext<chainsqlParser::ErrorContext>(i);
}


size_t chainsqlParser::ParseContext::getRuleIndex() const {
  return chainsqlParser::RuleParse;
}

void chainsqlParser::ParseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParse(this);
}

void chainsqlParser::ParseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParse(this);
}

chainsqlParser::ParseContext* chainsqlParser::parse() {
  ParseContext *_localctx = _tracker.createInstance<ParseContext>(_ctx, getState());
  enterRule(_localctx, 0, chainsqlParser::RuleParse);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << chainsqlParser::SCOL)
      | (1ULL << chainsqlParser::K_CREATE)
      | (1ULL << chainsqlParser::K_DELETE))) != 0) || ((((_la - 88) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 88)) & ((1ULL << (chainsqlParser::K_INSERT - 88))
      | (1ULL << (chainsqlParser::K_SELECT - 88))
      | (1ULL << (chainsqlParser::K_SHOW - 88))
      | (1ULL << (chainsqlParser::K_UPDATE - 88)))) != 0) || _la == chainsqlParser::UNEXPECTED_CHAR) {
      setState(94);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case chainsqlParser::SCOL:
        case chainsqlParser::K_CREATE:
        case chainsqlParser::K_DELETE:
        case chainsqlParser::K_INSERT:
        case chainsqlParser::K_SELECT:
        case chainsqlParser::K_SHOW:
        case chainsqlParser::K_UPDATE: {
          setState(92);
          sql_stmt_list();
          break;
        }

        case chainsqlParser::UNEXPECTED_CHAR: {
          setState(93);
          error();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(98);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(99);
    match(chainsqlParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ErrorContext ------------------------------------------------------------------

chainsqlParser::ErrorContext::ErrorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::ErrorContext::UNEXPECTED_CHAR() {
  return getToken(chainsqlParser::UNEXPECTED_CHAR, 0);
}


size_t chainsqlParser::ErrorContext::getRuleIndex() const {
  return chainsqlParser::RuleError;
}

void chainsqlParser::ErrorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterError(this);
}

void chainsqlParser::ErrorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitError(this);
}

chainsqlParser::ErrorContext* chainsqlParser::error() {
  ErrorContext *_localctx = _tracker.createInstance<ErrorContext>(_ctx, getState());
  enterRule(_localctx, 2, chainsqlParser::RuleError);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    dynamic_cast<ErrorContext *>(_localctx)->unexpected_charToken = match(chainsqlParser::UNEXPECTED_CHAR);
     
         throw new RuntimeException("UNEXPECTED_CHAR=" + (dynamic_cast<ErrorContext *>(_localctx)->unexpected_charToken != nullptr ? dynamic_cast<ErrorContext *>(_localctx)->unexpected_charToken->getText() : "")); 
       
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sql_stmt_listContext ------------------------------------------------------------------

chainsqlParser::Sql_stmt_listContext::Sql_stmt_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<chainsqlParser::Sql_stmtContext *> chainsqlParser::Sql_stmt_listContext::sql_stmt() {
  return getRuleContexts<chainsqlParser::Sql_stmtContext>();
}

chainsqlParser::Sql_stmtContext* chainsqlParser::Sql_stmt_listContext::sql_stmt(size_t i) {
  return getRuleContext<chainsqlParser::Sql_stmtContext>(i);
}


size_t chainsqlParser::Sql_stmt_listContext::getRuleIndex() const {
  return chainsqlParser::RuleSql_stmt_list;
}

void chainsqlParser::Sql_stmt_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSql_stmt_list(this);
}

void chainsqlParser::Sql_stmt_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSql_stmt_list(this);
}

chainsqlParser::Sql_stmt_listContext* chainsqlParser::sql_stmt_list() {
  Sql_stmt_listContext *_localctx = _tracker.createInstance<Sql_stmt_listContext>(_ctx, getState());
  enterRule(_localctx, 4, chainsqlParser::RuleSql_stmt_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(107);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == chainsqlParser::SCOL) {
      setState(104);
      match(chainsqlParser::SCOL);
      setState(109);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(110);
    sql_stmt();
    setState(119);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(112); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(111);
          match(chainsqlParser::SCOL);
          setState(114); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == chainsqlParser::SCOL);
        setState(116);
        sql_stmt(); 
      }
      setState(121);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(125);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(122);
        match(chainsqlParser::SCOL); 
      }
      setState(127);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sql_stmtContext ------------------------------------------------------------------

chainsqlParser::Sql_stmtContext::Sql_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Create_index_stmtContext* chainsqlParser::Sql_stmtContext::create_index_stmt() {
  return getRuleContext<chainsqlParser::Create_index_stmtContext>(0);
}

chainsqlParser::Create_table_stmtContext* chainsqlParser::Sql_stmtContext::create_table_stmt() {
  return getRuleContext<chainsqlParser::Create_table_stmtContext>(0);
}

chainsqlParser::Delete_stmt_limitedContext* chainsqlParser::Sql_stmtContext::delete_stmt_limited() {
  return getRuleContext<chainsqlParser::Delete_stmt_limitedContext>(0);
}

chainsqlParser::Insert_stmtContext* chainsqlParser::Sql_stmtContext::insert_stmt() {
  return getRuleContext<chainsqlParser::Insert_stmtContext>(0);
}

chainsqlParser::Select_stmtContext* chainsqlParser::Sql_stmtContext::select_stmt() {
  return getRuleContext<chainsqlParser::Select_stmtContext>(0);
}

chainsqlParser::Update_stmt_limitedContext* chainsqlParser::Sql_stmtContext::update_stmt_limited() {
  return getRuleContext<chainsqlParser::Update_stmt_limitedContext>(0);
}

chainsqlParser::Show_tables_stmtContext* chainsqlParser::Sql_stmtContext::show_tables_stmt() {
  return getRuleContext<chainsqlParser::Show_tables_stmtContext>(0);
}


size_t chainsqlParser::Sql_stmtContext::getRuleIndex() const {
  return chainsqlParser::RuleSql_stmt;
}

void chainsqlParser::Sql_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSql_stmt(this);
}

void chainsqlParser::Sql_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSql_stmt(this);
}

chainsqlParser::Sql_stmtContext* chainsqlParser::sql_stmt() {
  Sql_stmtContext *_localctx = _tracker.createInstance<Sql_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, chainsqlParser::RuleSql_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(128);
      create_index_stmt();
      break;
    }

    case 2: {
      setState(129);
      create_table_stmt();
      break;
    }

    case 3: {
      setState(130);
      delete_stmt_limited();
      break;
    }

    case 4: {
      setState(131);
      insert_stmt();
      break;
    }

    case 5: {
      setState(132);
      select_stmt();
      break;
    }

    case 6: {
      setState(133);
      update_stmt_limited();
      break;
    }

    case 7: {
      setState(134);
      show_tables_stmt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_index_stmtContext ------------------------------------------------------------------

chainsqlParser::Create_index_stmtContext::Create_index_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Create_index_stmtContext::K_CREATE() {
  return getToken(chainsqlParser::K_CREATE, 0);
}

tree::TerminalNode* chainsqlParser::Create_index_stmtContext::K_INDEX() {
  return getToken(chainsqlParser::K_INDEX, 0);
}

chainsqlParser::Index_nameContext* chainsqlParser::Create_index_stmtContext::index_name() {
  return getRuleContext<chainsqlParser::Index_nameContext>(0);
}

tree::TerminalNode* chainsqlParser::Create_index_stmtContext::K_ON() {
  return getToken(chainsqlParser::K_ON, 0);
}

chainsqlParser::Table_nameContext* chainsqlParser::Create_index_stmtContext::table_name() {
  return getRuleContext<chainsqlParser::Table_nameContext>(0);
}

std::vector<chainsqlParser::Indexed_columnContext *> chainsqlParser::Create_index_stmtContext::indexed_column() {
  return getRuleContexts<chainsqlParser::Indexed_columnContext>();
}

chainsqlParser::Indexed_columnContext* chainsqlParser::Create_index_stmtContext::indexed_column(size_t i) {
  return getRuleContext<chainsqlParser::Indexed_columnContext>(i);
}

tree::TerminalNode* chainsqlParser::Create_index_stmtContext::K_UNIQUE() {
  return getToken(chainsqlParser::K_UNIQUE, 0);
}


size_t chainsqlParser::Create_index_stmtContext::getRuleIndex() const {
  return chainsqlParser::RuleCreate_index_stmt;
}

void chainsqlParser::Create_index_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_index_stmt(this);
}

void chainsqlParser::Create_index_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_index_stmt(this);
}

chainsqlParser::Create_index_stmtContext* chainsqlParser::create_index_stmt() {
  Create_index_stmtContext *_localctx = _tracker.createInstance<Create_index_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, chainsqlParser::RuleCreate_index_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(chainsqlParser::K_CREATE);
    setState(139);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_UNIQUE) {
      setState(138);
      match(chainsqlParser::K_UNIQUE);
    }
    setState(141);
    match(chainsqlParser::K_INDEX);
    setState(142);
    index_name();
    setState(143);
    match(chainsqlParser::K_ON);
    setState(144);
    table_name();
    setState(145);
    match(chainsqlParser::OPEN_PAR);
    setState(146);
    indexed_column();
    setState(151);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == chainsqlParser::COMMA) {
      setState(147);
      match(chainsqlParser::COMMA);
      setState(148);
      indexed_column();
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(154);
    match(chainsqlParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_table_stmtContext ------------------------------------------------------------------

chainsqlParser::Create_table_stmtContext::Create_table_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Create_table_stmtContext::K_CREATE() {
  return getToken(chainsqlParser::K_CREATE, 0);
}

tree::TerminalNode* chainsqlParser::Create_table_stmtContext::K_TABLE() {
  return getToken(chainsqlParser::K_TABLE, 0);
}

chainsqlParser::Table_nameContext* chainsqlParser::Create_table_stmtContext::table_name() {
  return getRuleContext<chainsqlParser::Table_nameContext>(0);
}

std::vector<chainsqlParser::Column_defContext *> chainsqlParser::Create_table_stmtContext::column_def() {
  return getRuleContexts<chainsqlParser::Column_defContext>();
}

chainsqlParser::Column_defContext* chainsqlParser::Create_table_stmtContext::column_def(size_t i) {
  return getRuleContext<chainsqlParser::Column_defContext>(i);
}


size_t chainsqlParser::Create_table_stmtContext::getRuleIndex() const {
  return chainsqlParser::RuleCreate_table_stmt;
}

void chainsqlParser::Create_table_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_table_stmt(this);
}

void chainsqlParser::Create_table_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_table_stmt(this);
}

chainsqlParser::Create_table_stmtContext* chainsqlParser::create_table_stmt() {
  Create_table_stmtContext *_localctx = _tracker.createInstance<Create_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, chainsqlParser::RuleCreate_table_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(chainsqlParser::K_CREATE);
    setState(157);
    match(chainsqlParser::K_TABLE);
    setState(158);
    table_name();
    setState(159);
    match(chainsqlParser::OPEN_PAR);
    setState(160);
    column_def();
    setState(165);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == chainsqlParser::COMMA) {
      setState(161);
      match(chainsqlParser::COMMA);
      setState(162);
      column_def();
      setState(167);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(168);
    match(chainsqlParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Delete_stmt_limitedContext ------------------------------------------------------------------

chainsqlParser::Delete_stmt_limitedContext::Delete_stmt_limitedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Delete_stmt_limitedContext::K_DELETE() {
  return getToken(chainsqlParser::K_DELETE, 0);
}

tree::TerminalNode* chainsqlParser::Delete_stmt_limitedContext::K_FROM() {
  return getToken(chainsqlParser::K_FROM, 0);
}

chainsqlParser::Qualified_table_nameContext* chainsqlParser::Delete_stmt_limitedContext::qualified_table_name() {
  return getRuleContext<chainsqlParser::Qualified_table_nameContext>(0);
}

tree::TerminalNode* chainsqlParser::Delete_stmt_limitedContext::K_LIMIT() {
  return getToken(chainsqlParser::K_LIMIT, 0);
}

std::vector<chainsqlParser::ExprContext *> chainsqlParser::Delete_stmt_limitedContext::expr() {
  return getRuleContexts<chainsqlParser::ExprContext>();
}

chainsqlParser::ExprContext* chainsqlParser::Delete_stmt_limitedContext::expr(size_t i) {
  return getRuleContext<chainsqlParser::ExprContext>(i);
}

tree::TerminalNode* chainsqlParser::Delete_stmt_limitedContext::K_WHERE() {
  return getToken(chainsqlParser::K_WHERE, 0);
}

tree::TerminalNode* chainsqlParser::Delete_stmt_limitedContext::K_ORDER() {
  return getToken(chainsqlParser::K_ORDER, 0);
}

tree::TerminalNode* chainsqlParser::Delete_stmt_limitedContext::K_BY() {
  return getToken(chainsqlParser::K_BY, 0);
}

std::vector<chainsqlParser::Ordering_termContext *> chainsqlParser::Delete_stmt_limitedContext::ordering_term() {
  return getRuleContexts<chainsqlParser::Ordering_termContext>();
}

chainsqlParser::Ordering_termContext* chainsqlParser::Delete_stmt_limitedContext::ordering_term(size_t i) {
  return getRuleContext<chainsqlParser::Ordering_termContext>(i);
}


size_t chainsqlParser::Delete_stmt_limitedContext::getRuleIndex() const {
  return chainsqlParser::RuleDelete_stmt_limited;
}

void chainsqlParser::Delete_stmt_limitedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelete_stmt_limited(this);
}

void chainsqlParser::Delete_stmt_limitedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelete_stmt_limited(this);
}

chainsqlParser::Delete_stmt_limitedContext* chainsqlParser::delete_stmt_limited() {
  Delete_stmt_limitedContext *_localctx = _tracker.createInstance<Delete_stmt_limitedContext>(_ctx, getState());
  enterRule(_localctx, 12, chainsqlParser::RuleDelete_stmt_limited);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(chainsqlParser::K_DELETE);
    setState(171);
    match(chainsqlParser::K_FROM);
    setState(172);
    qualified_table_name();
    setState(175);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_WHERE) {
      setState(173);
      match(chainsqlParser::K_WHERE);
      setState(174);
      expr(0);
    }
    setState(187);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_ORDER) {
      setState(177);
      match(chainsqlParser::K_ORDER);
      setState(178);
      match(chainsqlParser::K_BY);
      setState(179);
      ordering_term();
      setState(184);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == chainsqlParser::COMMA) {
        setState(180);
        match(chainsqlParser::COMMA);
        setState(181);
        ordering_term();
        setState(186);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(189);
    match(chainsqlParser::K_LIMIT);
    setState(190);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Insert_stmtContext ------------------------------------------------------------------

chainsqlParser::Insert_stmtContext::Insert_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Insert_stmtContext::K_INSERT() {
  return getToken(chainsqlParser::K_INSERT, 0);
}

tree::TerminalNode* chainsqlParser::Insert_stmtContext::K_INTO() {
  return getToken(chainsqlParser::K_INTO, 0);
}

chainsqlParser::Table_nameContext* chainsqlParser::Insert_stmtContext::table_name() {
  return getRuleContext<chainsqlParser::Table_nameContext>(0);
}

tree::TerminalNode* chainsqlParser::Insert_stmtContext::K_VALUES() {
  return getToken(chainsqlParser::K_VALUES, 0);
}

std::vector<chainsqlParser::ExprContext *> chainsqlParser::Insert_stmtContext::expr() {
  return getRuleContexts<chainsqlParser::ExprContext>();
}

chainsqlParser::ExprContext* chainsqlParser::Insert_stmtContext::expr(size_t i) {
  return getRuleContext<chainsqlParser::ExprContext>(i);
}

std::vector<chainsqlParser::Column_nameContext *> chainsqlParser::Insert_stmtContext::column_name() {
  return getRuleContexts<chainsqlParser::Column_nameContext>();
}

chainsqlParser::Column_nameContext* chainsqlParser::Insert_stmtContext::column_name(size_t i) {
  return getRuleContext<chainsqlParser::Column_nameContext>(i);
}


size_t chainsqlParser::Insert_stmtContext::getRuleIndex() const {
  return chainsqlParser::RuleInsert_stmt;
}

void chainsqlParser::Insert_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_stmt(this);
}

void chainsqlParser::Insert_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_stmt(this);
}

chainsqlParser::Insert_stmtContext* chainsqlParser::insert_stmt() {
  Insert_stmtContext *_localctx = _tracker.createInstance<Insert_stmtContext>(_ctx, getState());
  enterRule(_localctx, 14, chainsqlParser::RuleInsert_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(chainsqlParser::K_INSERT);
    setState(193);
    match(chainsqlParser::K_INTO);
    setState(194);
    table_name();

    setState(195);
    match(chainsqlParser::OPEN_PAR);
    setState(196);
    column_name();
    setState(201);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == chainsqlParser::COMMA) {
      setState(197);
      match(chainsqlParser::COMMA);
      setState(198);
      column_name();
      setState(203);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(204);
    match(chainsqlParser::CLOSE_PAR);
    setState(206);
    match(chainsqlParser::K_VALUES);
    setState(207);
    match(chainsqlParser::OPEN_PAR);
    setState(208);
    expr(0);
    setState(213);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == chainsqlParser::COMMA) {
      setState(209);
      match(chainsqlParser::COMMA);
      setState(210);
      expr(0);
      setState(215);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(216);
    match(chainsqlParser::CLOSE_PAR);
    setState(231);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == chainsqlParser::COMMA) {
      setState(217);
      match(chainsqlParser::COMMA);
      setState(218);
      match(chainsqlParser::OPEN_PAR);
      setState(219);
      expr(0);
      setState(224);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == chainsqlParser::COMMA) {
        setState(220);
        match(chainsqlParser::COMMA);
        setState(221);
        expr(0);
        setState(226);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(227);
      match(chainsqlParser::CLOSE_PAR);
      setState(233);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_stmtContext ------------------------------------------------------------------

chainsqlParser::Select_stmtContext::Select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_SELECT() {
  return getToken(chainsqlParser::K_SELECT, 0);
}

std::vector<chainsqlParser::Result_columnContext *> chainsqlParser::Select_stmtContext::result_column() {
  return getRuleContexts<chainsqlParser::Result_columnContext>();
}

chainsqlParser::Result_columnContext* chainsqlParser::Select_stmtContext::result_column(size_t i) {
  return getRuleContext<chainsqlParser::Result_columnContext>(i);
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_FROM() {
  return getToken(chainsqlParser::K_FROM, 0);
}

std::vector<chainsqlParser::Table_or_subqueryContext *> chainsqlParser::Select_stmtContext::table_or_subquery() {
  return getRuleContexts<chainsqlParser::Table_or_subqueryContext>();
}

chainsqlParser::Table_or_subqueryContext* chainsqlParser::Select_stmtContext::table_or_subquery(size_t i) {
  return getRuleContext<chainsqlParser::Table_or_subqueryContext>(i);
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_WHERE() {
  return getToken(chainsqlParser::K_WHERE, 0);
}

std::vector<chainsqlParser::ExprContext *> chainsqlParser::Select_stmtContext::expr() {
  return getRuleContexts<chainsqlParser::ExprContext>();
}

chainsqlParser::ExprContext* chainsqlParser::Select_stmtContext::expr(size_t i) {
  return getRuleContext<chainsqlParser::ExprContext>(i);
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_GROUP() {
  return getToken(chainsqlParser::K_GROUP, 0);
}

std::vector<tree::TerminalNode *> chainsqlParser::Select_stmtContext::K_BY() {
  return getTokens(chainsqlParser::K_BY);
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_BY(size_t i) {
  return getToken(chainsqlParser::K_BY, i);
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_ORDER() {
  return getToken(chainsqlParser::K_ORDER, 0);
}

std::vector<chainsqlParser::Ordering_termContext *> chainsqlParser::Select_stmtContext::ordering_term() {
  return getRuleContexts<chainsqlParser::Ordering_termContext>();
}

chainsqlParser::Ordering_termContext* chainsqlParser::Select_stmtContext::ordering_term(size_t i) {
  return getRuleContext<chainsqlParser::Ordering_termContext>(i);
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_LIMIT() {
  return getToken(chainsqlParser::K_LIMIT, 0);
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_DISTINCT() {
  return getToken(chainsqlParser::K_DISTINCT, 0);
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_ALL() {
  return getToken(chainsqlParser::K_ALL, 0);
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_HAVING() {
  return getToken(chainsqlParser::K_HAVING, 0);
}

tree::TerminalNode* chainsqlParser::Select_stmtContext::K_OFFSET() {
  return getToken(chainsqlParser::K_OFFSET, 0);
}


size_t chainsqlParser::Select_stmtContext::getRuleIndex() const {
  return chainsqlParser::RuleSelect_stmt;
}

void chainsqlParser::Select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_stmt(this);
}

void chainsqlParser::Select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_stmt(this);
}

chainsqlParser::Select_stmtContext* chainsqlParser::select_stmt() {
  Select_stmtContext *_localctx = _tracker.createInstance<Select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 16, chainsqlParser::RuleSelect_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    match(chainsqlParser::K_SELECT);
    setState(236);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(235);
      _la = _input->LA(1);
      if (!(_la == chainsqlParser::K_ALL

      || _la == chainsqlParser::K_DISTINCT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    }
    setState(238);
    result_column();
    setState(243);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == chainsqlParser::COMMA) {
      setState(239);
      match(chainsqlParser::COMMA);
      setState(240);
      result_column();
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(246);
    match(chainsqlParser::K_FROM);
    setState(247);
    table_or_subquery();
    setState(252);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == chainsqlParser::COMMA) {
      setState(248);
      match(chainsqlParser::COMMA);
      setState(249);
      table_or_subquery();
      setState(254);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_WHERE) {
      setState(255);
      match(chainsqlParser::K_WHERE);
      setState(256);
      expr(0);
    }
    setState(273);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_GROUP) {
      setState(259);
      match(chainsqlParser::K_GROUP);
      setState(260);
      match(chainsqlParser::K_BY);
      setState(261);
      expr(0);
      setState(266);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == chainsqlParser::COMMA) {
        setState(262);
        match(chainsqlParser::COMMA);
        setState(263);
        expr(0);
        setState(268);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(271);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == chainsqlParser::K_HAVING) {
        setState(269);
        match(chainsqlParser::K_HAVING);
        setState(270);
        expr(0);
      }
    }
    setState(285);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_ORDER) {
      setState(275);
      match(chainsqlParser::K_ORDER);
      setState(276);
      match(chainsqlParser::K_BY);
      setState(277);
      ordering_term();
      setState(282);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == chainsqlParser::COMMA) {
        setState(278);
        match(chainsqlParser::COMMA);
        setState(279);
        ordering_term();
        setState(284);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_LIMIT) {
      setState(287);
      match(chainsqlParser::K_LIMIT);
      setState(288);
      expr(0);
      setState(291);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == chainsqlParser::K_OFFSET) {
        setState(289);
        match(chainsqlParser::K_OFFSET);
        setState(290);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Update_stmt_limitedContext ------------------------------------------------------------------

chainsqlParser::Update_stmt_limitedContext::Update_stmt_limitedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Update_stmt_limitedContext::K_UPDATE() {
  return getToken(chainsqlParser::K_UPDATE, 0);
}

chainsqlParser::Qualified_table_nameContext* chainsqlParser::Update_stmt_limitedContext::qualified_table_name() {
  return getRuleContext<chainsqlParser::Qualified_table_nameContext>(0);
}

tree::TerminalNode* chainsqlParser::Update_stmt_limitedContext::K_SET() {
  return getToken(chainsqlParser::K_SET, 0);
}

std::vector<chainsqlParser::Column_nameContext *> chainsqlParser::Update_stmt_limitedContext::column_name() {
  return getRuleContexts<chainsqlParser::Column_nameContext>();
}

chainsqlParser::Column_nameContext* chainsqlParser::Update_stmt_limitedContext::column_name(size_t i) {
  return getRuleContext<chainsqlParser::Column_nameContext>(i);
}

std::vector<chainsqlParser::ExprContext *> chainsqlParser::Update_stmt_limitedContext::expr() {
  return getRuleContexts<chainsqlParser::ExprContext>();
}

chainsqlParser::ExprContext* chainsqlParser::Update_stmt_limitedContext::expr(size_t i) {
  return getRuleContext<chainsqlParser::ExprContext>(i);
}

tree::TerminalNode* chainsqlParser::Update_stmt_limitedContext::K_LIMIT() {
  return getToken(chainsqlParser::K_LIMIT, 0);
}

tree::TerminalNode* chainsqlParser::Update_stmt_limitedContext::K_WHERE() {
  return getToken(chainsqlParser::K_WHERE, 0);
}

tree::TerminalNode* chainsqlParser::Update_stmt_limitedContext::K_ORDER() {
  return getToken(chainsqlParser::K_ORDER, 0);
}

tree::TerminalNode* chainsqlParser::Update_stmt_limitedContext::K_BY() {
  return getToken(chainsqlParser::K_BY, 0);
}

std::vector<chainsqlParser::Ordering_termContext *> chainsqlParser::Update_stmt_limitedContext::ordering_term() {
  return getRuleContexts<chainsqlParser::Ordering_termContext>();
}

chainsqlParser::Ordering_termContext* chainsqlParser::Update_stmt_limitedContext::ordering_term(size_t i) {
  return getRuleContext<chainsqlParser::Ordering_termContext>(i);
}


size_t chainsqlParser::Update_stmt_limitedContext::getRuleIndex() const {
  return chainsqlParser::RuleUpdate_stmt_limited;
}

void chainsqlParser::Update_stmt_limitedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpdate_stmt_limited(this);
}

void chainsqlParser::Update_stmt_limitedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpdate_stmt_limited(this);
}

chainsqlParser::Update_stmt_limitedContext* chainsqlParser::update_stmt_limited() {
  Update_stmt_limitedContext *_localctx = _tracker.createInstance<Update_stmt_limitedContext>(_ctx, getState());
  enterRule(_localctx, 18, chainsqlParser::RuleUpdate_stmt_limited);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    match(chainsqlParser::K_UPDATE);
    setState(296);
    qualified_table_name();
    setState(297);
    match(chainsqlParser::K_SET);
    setState(298);
    column_name();
    setState(299);
    match(chainsqlParser::ASSIGN);
    setState(300);
    expr(0);
    setState(308);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == chainsqlParser::COMMA) {
      setState(301);
      match(chainsqlParser::COMMA);
      setState(302);
      column_name();
      setState(303);
      match(chainsqlParser::ASSIGN);
      setState(304);
      expr(0);
      setState(310);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(313);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_WHERE) {
      setState(311);
      match(chainsqlParser::K_WHERE);
      setState(312);
      expr(0);
    }
    setState(325);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_ORDER) {
      setState(315);
      match(chainsqlParser::K_ORDER);
      setState(316);
      match(chainsqlParser::K_BY);
      setState(317);
      ordering_term();
      setState(322);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == chainsqlParser::COMMA) {
        setState(318);
        match(chainsqlParser::COMMA);
        setState(319);
        ordering_term();
        setState(324);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(327);
    match(chainsqlParser::K_LIMIT);
    setState(328);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Show_tables_stmtContext ------------------------------------------------------------------

chainsqlParser::Show_tables_stmtContext::Show_tables_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Show_tables_stmtContext::K_SHOW() {
  return getToken(chainsqlParser::K_SHOW, 0);
}

tree::TerminalNode* chainsqlParser::Show_tables_stmtContext::K_TABLES() {
  return getToken(chainsqlParser::K_TABLES, 0);
}


size_t chainsqlParser::Show_tables_stmtContext::getRuleIndex() const {
  return chainsqlParser::RuleShow_tables_stmt;
}

void chainsqlParser::Show_tables_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShow_tables_stmt(this);
}

void chainsqlParser::Show_tables_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShow_tables_stmt(this);
}

chainsqlParser::Show_tables_stmtContext* chainsqlParser::show_tables_stmt() {
  Show_tables_stmtContext *_localctx = _tracker.createInstance<Show_tables_stmtContext>(_ctx, getState());
  enterRule(_localctx, 20, chainsqlParser::RuleShow_tables_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(chainsqlParser::K_SHOW);
    setState(331);
    match(chainsqlParser::K_TABLES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_defContext ------------------------------------------------------------------

chainsqlParser::Column_defContext::Column_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Column_nameContext* chainsqlParser::Column_defContext::column_name() {
  return getRuleContext<chainsqlParser::Column_nameContext>(0);
}

chainsqlParser::Type_nameContext* chainsqlParser::Column_defContext::type_name() {
  return getRuleContext<chainsqlParser::Type_nameContext>(0);
}


size_t chainsqlParser::Column_defContext::getRuleIndex() const {
  return chainsqlParser::RuleColumn_def;
}

void chainsqlParser::Column_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_def(this);
}

void chainsqlParser::Column_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_def(this);
}

chainsqlParser::Column_defContext* chainsqlParser::column_def() {
  Column_defContext *_localctx = _tracker.createInstance<Column_defContext>(_ctx, getState());
  enterRule(_localctx, 22, chainsqlParser::RuleColumn_def);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    column_name();
    setState(334);
    type_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_nameContext ------------------------------------------------------------------

chainsqlParser::Type_nameContext::Type_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<chainsqlParser::NameContext *> chainsqlParser::Type_nameContext::name() {
  return getRuleContexts<chainsqlParser::NameContext>();
}

chainsqlParser::NameContext* chainsqlParser::Type_nameContext::name(size_t i) {
  return getRuleContext<chainsqlParser::NameContext>(i);
}

std::vector<chainsqlParser::Signed_numberContext *> chainsqlParser::Type_nameContext::signed_number() {
  return getRuleContexts<chainsqlParser::Signed_numberContext>();
}

chainsqlParser::Signed_numberContext* chainsqlParser::Type_nameContext::signed_number(size_t i) {
  return getRuleContext<chainsqlParser::Signed_numberContext>(i);
}


size_t chainsqlParser::Type_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleType_name;
}

void chainsqlParser::Type_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_name(this);
}

void chainsqlParser::Type_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_name(this);
}

chainsqlParser::Type_nameContext* chainsqlParser::type_name() {
  Type_nameContext *_localctx = _tracker.createInstance<Type_nameContext>(_ctx, getState());
  enterRule(_localctx, 24, chainsqlParser::RuleType_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(337); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(336);
              name();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(339); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(351);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(341);
      match(chainsqlParser::OPEN_PAR);
      setState(342);
      signed_number();
      setState(343);
      match(chainsqlParser::CLOSE_PAR);
      break;
    }

    case 2: {
      setState(345);
      match(chainsqlParser::OPEN_PAR);
      setState(346);
      signed_number();
      setState(347);
      match(chainsqlParser::COMMA);
      setState(348);
      signed_number();
      setState(349);
      match(chainsqlParser::CLOSE_PAR);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

chainsqlParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Literal_valueContext* chainsqlParser::ExprContext::literal_value() {
  return getRuleContext<chainsqlParser::Literal_valueContext>(0);
}

chainsqlParser::Column_nameContext* chainsqlParser::ExprContext::column_name() {
  return getRuleContext<chainsqlParser::Column_nameContext>(0);
}

chainsqlParser::Table_nameContext* chainsqlParser::ExprContext::table_name() {
  return getRuleContext<chainsqlParser::Table_nameContext>(0);
}

chainsqlParser::Function_nameContext* chainsqlParser::ExprContext::function_name() {
  return getRuleContext<chainsqlParser::Function_nameContext>(0);
}

std::vector<chainsqlParser::ExprContext *> chainsqlParser::ExprContext::expr() {
  return getRuleContexts<chainsqlParser::ExprContext>();
}

chainsqlParser::ExprContext* chainsqlParser::ExprContext::expr(size_t i) {
  return getRuleContext<chainsqlParser::ExprContext>(i);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_DISTINCT() {
  return getToken(chainsqlParser::K_DISTINCT, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_IS() {
  return getToken(chainsqlParser::K_IS, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_NOT() {
  return getToken(chainsqlParser::K_NOT, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_IN() {
  return getToken(chainsqlParser::K_IN, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_LIKE() {
  return getToken(chainsqlParser::K_LIKE, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_GLOB() {
  return getToken(chainsqlParser::K_GLOB, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_MATCH() {
  return getToken(chainsqlParser::K_MATCH, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_REGEXP() {
  return getToken(chainsqlParser::K_REGEXP, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_AND() {
  return getToken(chainsqlParser::K_AND, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_OR() {
  return getToken(chainsqlParser::K_OR, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_ISNULL() {
  return getToken(chainsqlParser::K_ISNULL, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_NOTNULL() {
  return getToken(chainsqlParser::K_NOTNULL, 0);
}

tree::TerminalNode* chainsqlParser::ExprContext::K_NULL() {
  return getToken(chainsqlParser::K_NULL, 0);
}


size_t chainsqlParser::ExprContext::getRuleIndex() const {
  return chainsqlParser::RuleExpr;
}

void chainsqlParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void chainsqlParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


chainsqlParser::ExprContext* chainsqlParser::expr() {
   return expr(0);
}

chainsqlParser::ExprContext* chainsqlParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  chainsqlParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  chainsqlParser::ExprContext *previousContext = _localctx;
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, chainsqlParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(383);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(354);
      literal_value();
      break;
    }

    case 2: {
      setState(358);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
      case 1: {
        setState(355);
        table_name();
        setState(356);
        match(chainsqlParser::DOT);
        break;
      }

      }
      setState(360);
      column_name();
      break;
    }

    case 3: {
      setState(361);
      function_name();
      setState(362);
      match(chainsqlParser::OPEN_PAR);
      setState(375);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case chainsqlParser::OPEN_PAR:
        case chainsqlParser::K_ABORT:
        case chainsqlParser::K_ACTION:
        case chainsqlParser::K_ADD:
        case chainsqlParser::K_AFTER:
        case chainsqlParser::K_ALL:
        case chainsqlParser::K_ALTER:
        case chainsqlParser::K_ANALYZE:
        case chainsqlParser::K_AND:
        case chainsqlParser::K_AS:
        case chainsqlParser::K_ASC:
        case chainsqlParser::K_ATTACH:
        case chainsqlParser::K_AUTOINCREMENT:
        case chainsqlParser::K_BEFORE:
        case chainsqlParser::K_BEGIN:
        case chainsqlParser::K_BETWEEN:
        case chainsqlParser::K_BY:
        case chainsqlParser::K_CASCADE:
        case chainsqlParser::K_CASE:
        case chainsqlParser::K_CAST:
        case chainsqlParser::K_CHECK:
        case chainsqlParser::K_COLLATE:
        case chainsqlParser::K_COLUMN:
        case chainsqlParser::K_COMMIT:
        case chainsqlParser::K_CONFLICT:
        case chainsqlParser::K_CONSTRAINT:
        case chainsqlParser::K_CREATE:
        case chainsqlParser::K_CROSS:
        case chainsqlParser::K_CURRENT_DATE:
        case chainsqlParser::K_CURRENT_TIME:
        case chainsqlParser::K_CURRENT_TIMESTAMP:
        case chainsqlParser::K_DATABASE:
        case chainsqlParser::K_DEFAULT:
        case chainsqlParser::K_DEFERRABLE:
        case chainsqlParser::K_DEFERRED:
        case chainsqlParser::K_DELETE:
        case chainsqlParser::K_DESC:
        case chainsqlParser::K_DETACH:
        case chainsqlParser::K_DISTINCT:
        case chainsqlParser::K_DROP:
        case chainsqlParser::K_EACH:
        case chainsqlParser::K_ELSE:
        case chainsqlParser::K_END:
        case chainsqlParser::K_ESCAPE:
        case chainsqlParser::K_EXCEPT:
        case chainsqlParser::K_EXCLUSIVE:
        case chainsqlParser::K_EXISTS:
        case chainsqlParser::K_EXPLAIN:
        case chainsqlParser::K_FAIL:
        case chainsqlParser::K_FOR:
        case chainsqlParser::K_FOREIGN:
        case chainsqlParser::K_FROM:
        case chainsqlParser::K_FULL:
        case chainsqlParser::K_GLOB:
        case chainsqlParser::K_GROUP:
        case chainsqlParser::K_HAVING:
        case chainsqlParser::K_IF:
        case chainsqlParser::K_IGNORE:
        case chainsqlParser::K_IMMEDIATE:
        case chainsqlParser::K_IN:
        case chainsqlParser::K_INDEX:
        case chainsqlParser::K_INDEXED:
        case chainsqlParser::K_INITIALLY:
        case chainsqlParser::K_INNER:
        case chainsqlParser::K_INSERT:
        case chainsqlParser::K_INSTEAD:
        case chainsqlParser::K_INTERSECT:
        case chainsqlParser::K_INTO:
        case chainsqlParser::K_IS:
        case chainsqlParser::K_ISNULL:
        case chainsqlParser::K_JOIN:
        case chainsqlParser::K_KEY:
        case chainsqlParser::K_LEFT:
        case chainsqlParser::K_LIKE:
        case chainsqlParser::K_LIMIT:
        case chainsqlParser::K_MATCH:
        case chainsqlParser::K_NATURAL:
        case chainsqlParser::K_NO:
        case chainsqlParser::K_NOT:
        case chainsqlParser::K_NOTNULL:
        case chainsqlParser::K_NULL:
        case chainsqlParser::K_OF:
        case chainsqlParser::K_OFFSET:
        case chainsqlParser::K_ON:
        case chainsqlParser::K_OR:
        case chainsqlParser::K_ORDER:
        case chainsqlParser::K_OUTER:
        case chainsqlParser::K_PLAN:
        case chainsqlParser::K_PRAGMA:
        case chainsqlParser::K_PRIMARY:
        case chainsqlParser::K_QUERY:
        case chainsqlParser::K_RAISE:
        case chainsqlParser::K_RECURSIVE:
        case chainsqlParser::K_REFERENCES:
        case chainsqlParser::K_REGEXP:
        case chainsqlParser::K_REINDEX:
        case chainsqlParser::K_RELEASE:
        case chainsqlParser::K_RENAME:
        case chainsqlParser::K_REPLACE:
        case chainsqlParser::K_RESTRICT:
        case chainsqlParser::K_RIGHT:
        case chainsqlParser::K_ROLLBACK:
        case chainsqlParser::K_ROW:
        case chainsqlParser::K_SAVEPOINT:
        case chainsqlParser::K_SELECT:
        case chainsqlParser::K_SET:
        case chainsqlParser::K_TABLE:
        case chainsqlParser::K_SHOW:
        case chainsqlParser::K_TABLES:
        case chainsqlParser::K_TEMP:
        case chainsqlParser::K_TEMPORARY:
        case chainsqlParser::K_THEN:
        case chainsqlParser::K_TO:
        case chainsqlParser::K_TRANSACTION:
        case chainsqlParser::K_TRIGGER:
        case chainsqlParser::K_UNION:
        case chainsqlParser::K_UNIQUE:
        case chainsqlParser::K_UPDATE:
        case chainsqlParser::K_USING:
        case chainsqlParser::K_VACUUM:
        case chainsqlParser::K_VALUES:
        case chainsqlParser::K_VIEW:
        case chainsqlParser::K_VIRTUAL:
        case chainsqlParser::K_WHEN:
        case chainsqlParser::K_WHERE:
        case chainsqlParser::K_WITH:
        case chainsqlParser::K_WITHOUT:
        case chainsqlParser::IDENTIFIER:
        case chainsqlParser::NUMERIC_LITERAL:
        case chainsqlParser::STRING_LITERAL:
        case chainsqlParser::BLOB_LITERAL: {
          setState(364);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
          case 1: {
            setState(363);
            match(chainsqlParser::K_DISTINCT);
            break;
          }

          }
          setState(366);
          expr(0);
          setState(371);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == chainsqlParser::COMMA) {
            setState(367);
            match(chainsqlParser::COMMA);
            setState(368);
            expr(0);
            setState(373);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case chainsqlParser::STAR: {
          setState(374);
          match(chainsqlParser::STAR);
          break;
        }

        case chainsqlParser::CLOSE_PAR: {
          break;
        }

      default:
        break;
      }
      setState(377);
      match(chainsqlParser::CLOSE_PAR);
      break;
    }

    case 4: {
      setState(379);
      match(chainsqlParser::OPEN_PAR);
      setState(380);
      expr(0);
      setState(381);
      match(chainsqlParser::CLOSE_PAR);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(425);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(423);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(385);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(386);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << chainsqlParser::LT)
            | (1ULL << chainsqlParser::LT_EQ)
            | (1ULL << chainsqlParser::GT)
            | (1ULL << chainsqlParser::GT_EQ))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(387);
          expr(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(388);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(401);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
          case 1: {
            setState(389);
            match(chainsqlParser::ASSIGN);
            break;
          }

          case 2: {
            setState(390);
            match(chainsqlParser::EQ);
            break;
          }

          case 3: {
            setState(391);
            match(chainsqlParser::NOT_EQ1);
            break;
          }

          case 4: {
            setState(392);
            match(chainsqlParser::NOT_EQ2);
            break;
          }

          case 5: {
            setState(393);
            match(chainsqlParser::K_IS);
            break;
          }

          case 6: {
            setState(394);
            match(chainsqlParser::K_IS);
            setState(395);
            match(chainsqlParser::K_NOT);
            break;
          }

          case 7: {
            setState(396);
            match(chainsqlParser::K_IN);
            break;
          }

          case 8: {
            setState(397);
            match(chainsqlParser::K_LIKE);
            break;
          }

          case 9: {
            setState(398);
            match(chainsqlParser::K_GLOB);
            break;
          }

          case 10: {
            setState(399);
            match(chainsqlParser::K_MATCH);
            break;
          }

          case 11: {
            setState(400);
            match(chainsqlParser::K_REGEXP);
            break;
          }

          }
          setState(403);
          expr(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(404);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(405);
          match(chainsqlParser::K_AND);
          setState(406);
          expr(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(407);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(408);
          match(chainsqlParser::K_OR);
          setState(409);
          expr(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(410);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(411);
          match(chainsqlParser::K_IS);
          setState(413);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
          case 1: {
            setState(412);
            match(chainsqlParser::K_NOT);
            break;
          }

          }
          setState(415);
          expr(3);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(416);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(421);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case chainsqlParser::K_ISNULL: {
              setState(417);
              match(chainsqlParser::K_ISNULL);
              break;
            }

            case chainsqlParser::K_NOTNULL: {
              setState(418);
              match(chainsqlParser::K_NOTNULL);
              break;
            }

            case chainsqlParser::K_NOT: {
              setState(419);
              match(chainsqlParser::K_NOT);
              setState(420);
              match(chainsqlParser::K_NULL);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          break;
        }

        } 
      }
      setState(427);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Indexed_columnContext ------------------------------------------------------------------

chainsqlParser::Indexed_columnContext::Indexed_columnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Column_nameContext* chainsqlParser::Indexed_columnContext::column_name() {
  return getRuleContext<chainsqlParser::Column_nameContext>(0);
}

tree::TerminalNode* chainsqlParser::Indexed_columnContext::K_ASC() {
  return getToken(chainsqlParser::K_ASC, 0);
}

tree::TerminalNode* chainsqlParser::Indexed_columnContext::K_DESC() {
  return getToken(chainsqlParser::K_DESC, 0);
}


size_t chainsqlParser::Indexed_columnContext::getRuleIndex() const {
  return chainsqlParser::RuleIndexed_column;
}

void chainsqlParser::Indexed_columnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexed_column(this);
}

void chainsqlParser::Indexed_columnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexed_column(this);
}

chainsqlParser::Indexed_columnContext* chainsqlParser::indexed_column() {
  Indexed_columnContext *_localctx = _tracker.createInstance<Indexed_columnContext>(_ctx, getState());
  enterRule(_localctx, 28, chainsqlParser::RuleIndexed_column);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    column_name();
    setState(430);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_ASC

    || _la == chainsqlParser::K_DESC) {
      setState(429);
      _la = _input->LA(1);
      if (!(_la == chainsqlParser::K_ASC

      || _la == chainsqlParser::K_DESC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qualified_table_nameContext ------------------------------------------------------------------

chainsqlParser::Qualified_table_nameContext::Qualified_table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Table_nameContext* chainsqlParser::Qualified_table_nameContext::table_name() {
  return getRuleContext<chainsqlParser::Table_nameContext>(0);
}


size_t chainsqlParser::Qualified_table_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleQualified_table_name;
}

void chainsqlParser::Qualified_table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualified_table_name(this);
}

void chainsqlParser::Qualified_table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualified_table_name(this);
}

chainsqlParser::Qualified_table_nameContext* chainsqlParser::qualified_table_name() {
  Qualified_table_nameContext *_localctx = _tracker.createInstance<Qualified_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 30, chainsqlParser::RuleQualified_table_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    table_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ordering_termContext ------------------------------------------------------------------

chainsqlParser::Ordering_termContext::Ordering_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::ExprContext* chainsqlParser::Ordering_termContext::expr() {
  return getRuleContext<chainsqlParser::ExprContext>(0);
}

tree::TerminalNode* chainsqlParser::Ordering_termContext::K_ASC() {
  return getToken(chainsqlParser::K_ASC, 0);
}

tree::TerminalNode* chainsqlParser::Ordering_termContext::K_DESC() {
  return getToken(chainsqlParser::K_DESC, 0);
}


size_t chainsqlParser::Ordering_termContext::getRuleIndex() const {
  return chainsqlParser::RuleOrdering_term;
}

void chainsqlParser::Ordering_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrdering_term(this);
}

void chainsqlParser::Ordering_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrdering_term(this);
}

chainsqlParser::Ordering_termContext* chainsqlParser::ordering_term() {
  Ordering_termContext *_localctx = _tracker.createInstance<Ordering_termContext>(_ctx, getState());
  enterRule(_localctx, 32, chainsqlParser::RuleOrdering_term);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434);
    expr(0);
    setState(436);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::K_ASC

    || _la == chainsqlParser::K_DESC) {
      setState(435);
      _la = _input->LA(1);
      if (!(_la == chainsqlParser::K_ASC

      || _la == chainsqlParser::K_DESC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pragma_valueContext ------------------------------------------------------------------

chainsqlParser::Pragma_valueContext::Pragma_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Signed_numberContext* chainsqlParser::Pragma_valueContext::signed_number() {
  return getRuleContext<chainsqlParser::Signed_numberContext>(0);
}

chainsqlParser::NameContext* chainsqlParser::Pragma_valueContext::name() {
  return getRuleContext<chainsqlParser::NameContext>(0);
}

tree::TerminalNode* chainsqlParser::Pragma_valueContext::STRING_LITERAL() {
  return getToken(chainsqlParser::STRING_LITERAL, 0);
}


size_t chainsqlParser::Pragma_valueContext::getRuleIndex() const {
  return chainsqlParser::RulePragma_value;
}

void chainsqlParser::Pragma_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma_value(this);
}

void chainsqlParser::Pragma_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma_value(this);
}

chainsqlParser::Pragma_valueContext* chainsqlParser::pragma_value() {
  Pragma_valueContext *_localctx = _tracker.createInstance<Pragma_valueContext>(_ctx, getState());
  enterRule(_localctx, 34, chainsqlParser::RulePragma_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(441);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(438);
      signed_number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(439);
      name();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(440);
      match(chainsqlParser::STRING_LITERAL);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Common_table_expressionContext ------------------------------------------------------------------

chainsqlParser::Common_table_expressionContext::Common_table_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Table_nameContext* chainsqlParser::Common_table_expressionContext::table_name() {
  return getRuleContext<chainsqlParser::Table_nameContext>(0);
}

tree::TerminalNode* chainsqlParser::Common_table_expressionContext::K_AS() {
  return getToken(chainsqlParser::K_AS, 0);
}

chainsqlParser::Select_stmtContext* chainsqlParser::Common_table_expressionContext::select_stmt() {
  return getRuleContext<chainsqlParser::Select_stmtContext>(0);
}

std::vector<chainsqlParser::Column_nameContext *> chainsqlParser::Common_table_expressionContext::column_name() {
  return getRuleContexts<chainsqlParser::Column_nameContext>();
}

chainsqlParser::Column_nameContext* chainsqlParser::Common_table_expressionContext::column_name(size_t i) {
  return getRuleContext<chainsqlParser::Column_nameContext>(i);
}


size_t chainsqlParser::Common_table_expressionContext::getRuleIndex() const {
  return chainsqlParser::RuleCommon_table_expression;
}

void chainsqlParser::Common_table_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommon_table_expression(this);
}

void chainsqlParser::Common_table_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommon_table_expression(this);
}

chainsqlParser::Common_table_expressionContext* chainsqlParser::common_table_expression() {
  Common_table_expressionContext *_localctx = _tracker.createInstance<Common_table_expressionContext>(_ctx, getState());
  enterRule(_localctx, 36, chainsqlParser::RuleCommon_table_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(443);
    table_name();
    setState(455);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::OPEN_PAR) {
      setState(444);
      match(chainsqlParser::OPEN_PAR);
      setState(445);
      column_name();
      setState(450);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == chainsqlParser::COMMA) {
        setState(446);
        match(chainsqlParser::COMMA);
        setState(447);
        column_name();
        setState(452);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(453);
      match(chainsqlParser::CLOSE_PAR);
    }
    setState(457);
    match(chainsqlParser::K_AS);
    setState(458);
    match(chainsqlParser::OPEN_PAR);
    setState(459);
    select_stmt();
    setState(460);
    match(chainsqlParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Result_columnContext ------------------------------------------------------------------

chainsqlParser::Result_columnContext::Result_columnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Table_nameContext* chainsqlParser::Result_columnContext::table_name() {
  return getRuleContext<chainsqlParser::Table_nameContext>(0);
}

chainsqlParser::Column_nameContext* chainsqlParser::Result_columnContext::column_name() {
  return getRuleContext<chainsqlParser::Column_nameContext>(0);
}

chainsqlParser::ExprContext* chainsqlParser::Result_columnContext::expr() {
  return getRuleContext<chainsqlParser::ExprContext>(0);
}

chainsqlParser::Column_aliasContext* chainsqlParser::Result_columnContext::column_alias() {
  return getRuleContext<chainsqlParser::Column_aliasContext>(0);
}

tree::TerminalNode* chainsqlParser::Result_columnContext::K_AS() {
  return getToken(chainsqlParser::K_AS, 0);
}


size_t chainsqlParser::Result_columnContext::getRuleIndex() const {
  return chainsqlParser::RuleResult_column;
}

void chainsqlParser::Result_columnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResult_column(this);
}

void chainsqlParser::Result_columnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResult_column(this);
}

chainsqlParser::Result_columnContext* chainsqlParser::result_column() {
  Result_columnContext *_localctx = _tracker.createInstance<Result_columnContext>(_ctx, getState());
  enterRule(_localctx, 38, chainsqlParser::RuleResult_column);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(478);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(462);
      match(chainsqlParser::STAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(463);
      table_name();
      setState(464);
      match(chainsqlParser::DOT);
      setState(465);
      match(chainsqlParser::STAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(467);
      table_name();
      setState(468);
      match(chainsqlParser::DOT);
      setState(469);
      column_name();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(471);
      expr(0);
      setState(476);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == chainsqlParser::K_AS || _la == chainsqlParser::IDENTIFIER

      || _la == chainsqlParser::STRING_LITERAL) {
        setState(473);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == chainsqlParser::K_AS) {
          setState(472);
          match(chainsqlParser::K_AS);
        }
        setState(475);
        column_alias();
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_or_subqueryContext ------------------------------------------------------------------

chainsqlParser::Table_or_subqueryContext::Table_or_subqueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Table_nameContext* chainsqlParser::Table_or_subqueryContext::table_name() {
  return getRuleContext<chainsqlParser::Table_nameContext>(0);
}

chainsqlParser::Table_aliasContext* chainsqlParser::Table_or_subqueryContext::table_alias() {
  return getRuleContext<chainsqlParser::Table_aliasContext>(0);
}

tree::TerminalNode* chainsqlParser::Table_or_subqueryContext::K_AS() {
  return getToken(chainsqlParser::K_AS, 0);
}


size_t chainsqlParser::Table_or_subqueryContext::getRuleIndex() const {
  return chainsqlParser::RuleTable_or_subquery;
}

void chainsqlParser::Table_or_subqueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_or_subquery(this);
}

void chainsqlParser::Table_or_subqueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_or_subquery(this);
}

chainsqlParser::Table_or_subqueryContext* chainsqlParser::table_or_subquery() {
  Table_or_subqueryContext *_localctx = _tracker.createInstance<Table_or_subqueryContext>(_ctx, getState());
  enterRule(_localctx, 40, chainsqlParser::RuleTable_or_subquery);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(480);
    table_name();
    setState(485);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(482);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
      case 1: {
        setState(481);
        match(chainsqlParser::K_AS);
        break;
      }

      }
      setState(484);
      table_alias();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_coreContext ------------------------------------------------------------------

chainsqlParser::Select_coreContext::Select_coreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Select_coreContext::K_SELECT() {
  return getToken(chainsqlParser::K_SELECT, 0);
}

std::vector<chainsqlParser::Result_columnContext *> chainsqlParser::Select_coreContext::result_column() {
  return getRuleContexts<chainsqlParser::Result_columnContext>();
}

chainsqlParser::Result_columnContext* chainsqlParser::Select_coreContext::result_column(size_t i) {
  return getRuleContext<chainsqlParser::Result_columnContext>(i);
}

tree::TerminalNode* chainsqlParser::Select_coreContext::K_FROM() {
  return getToken(chainsqlParser::K_FROM, 0);
}

std::vector<chainsqlParser::Table_or_subqueryContext *> chainsqlParser::Select_coreContext::table_or_subquery() {
  return getRuleContexts<chainsqlParser::Table_or_subqueryContext>();
}

chainsqlParser::Table_or_subqueryContext* chainsqlParser::Select_coreContext::table_or_subquery(size_t i) {
  return getRuleContext<chainsqlParser::Table_or_subqueryContext>(i);
}

tree::TerminalNode* chainsqlParser::Select_coreContext::K_WHERE() {
  return getToken(chainsqlParser::K_WHERE, 0);
}

std::vector<chainsqlParser::ExprContext *> chainsqlParser::Select_coreContext::expr() {
  return getRuleContexts<chainsqlParser::ExprContext>();
}

chainsqlParser::ExprContext* chainsqlParser::Select_coreContext::expr(size_t i) {
  return getRuleContext<chainsqlParser::ExprContext>(i);
}

tree::TerminalNode* chainsqlParser::Select_coreContext::K_GROUP() {
  return getToken(chainsqlParser::K_GROUP, 0);
}

tree::TerminalNode* chainsqlParser::Select_coreContext::K_BY() {
  return getToken(chainsqlParser::K_BY, 0);
}

tree::TerminalNode* chainsqlParser::Select_coreContext::K_DISTINCT() {
  return getToken(chainsqlParser::K_DISTINCT, 0);
}

tree::TerminalNode* chainsqlParser::Select_coreContext::K_ALL() {
  return getToken(chainsqlParser::K_ALL, 0);
}

tree::TerminalNode* chainsqlParser::Select_coreContext::K_HAVING() {
  return getToken(chainsqlParser::K_HAVING, 0);
}

tree::TerminalNode* chainsqlParser::Select_coreContext::K_VALUES() {
  return getToken(chainsqlParser::K_VALUES, 0);
}


size_t chainsqlParser::Select_coreContext::getRuleIndex() const {
  return chainsqlParser::RuleSelect_core;
}

void chainsqlParser::Select_coreContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_core(this);
}

void chainsqlParser::Select_coreContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_core(this);
}

chainsqlParser::Select_coreContext* chainsqlParser::select_core() {
  Select_coreContext *_localctx = _tracker.createInstance<Select_coreContext>(_ctx, getState());
  enterRule(_localctx, 42, chainsqlParser::RuleSelect_core);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(556);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case chainsqlParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(487);
        match(chainsqlParser::K_SELECT);
        setState(489);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
        case 1: {
          setState(488);
          _la = _input->LA(1);
          if (!(_la == chainsqlParser::K_ALL

          || _la == chainsqlParser::K_DISTINCT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        }
        setState(491);
        result_column();
        setState(496);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == chainsqlParser::COMMA) {
          setState(492);
          match(chainsqlParser::COMMA);
          setState(493);
          result_column();
          setState(498);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(499);
        match(chainsqlParser::K_FROM);

        setState(500);
        table_or_subquery();
        setState(505);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == chainsqlParser::COMMA) {
          setState(501);
          match(chainsqlParser::COMMA);
          setState(502);
          table_or_subquery();
          setState(507);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(510);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == chainsqlParser::K_WHERE) {
          setState(508);
          match(chainsqlParser::K_WHERE);
          setState(509);
          expr(0);
        }
        setState(526);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == chainsqlParser::K_GROUP) {
          setState(512);
          match(chainsqlParser::K_GROUP);
          setState(513);
          match(chainsqlParser::K_BY);
          setState(514);
          expr(0);
          setState(519);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == chainsqlParser::COMMA) {
            setState(515);
            match(chainsqlParser::COMMA);
            setState(516);
            expr(0);
            setState(521);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(524);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == chainsqlParser::K_HAVING) {
            setState(522);
            match(chainsqlParser::K_HAVING);
            setState(523);
            expr(0);
          }
        }
        break;
      }

      case chainsqlParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(528);
        match(chainsqlParser::K_VALUES);
        setState(529);
        match(chainsqlParser::OPEN_PAR);
        setState(530);
        expr(0);
        setState(535);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == chainsqlParser::COMMA) {
          setState(531);
          match(chainsqlParser::COMMA);
          setState(532);
          expr(0);
          setState(537);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(538);
        match(chainsqlParser::CLOSE_PAR);
        setState(553);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == chainsqlParser::COMMA) {
          setState(539);
          match(chainsqlParser::COMMA);
          setState(540);
          match(chainsqlParser::OPEN_PAR);
          setState(541);
          expr(0);
          setState(546);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == chainsqlParser::COMMA) {
            setState(542);
            match(chainsqlParser::COMMA);
            setState(543);
            expr(0);
            setState(548);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(549);
          match(chainsqlParser::CLOSE_PAR);
          setState(555);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cte_table_nameContext ------------------------------------------------------------------

chainsqlParser::Cte_table_nameContext::Cte_table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Table_nameContext* chainsqlParser::Cte_table_nameContext::table_name() {
  return getRuleContext<chainsqlParser::Table_nameContext>(0);
}

std::vector<chainsqlParser::Column_nameContext *> chainsqlParser::Cte_table_nameContext::column_name() {
  return getRuleContexts<chainsqlParser::Column_nameContext>();
}

chainsqlParser::Column_nameContext* chainsqlParser::Cte_table_nameContext::column_name(size_t i) {
  return getRuleContext<chainsqlParser::Column_nameContext>(i);
}


size_t chainsqlParser::Cte_table_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleCte_table_name;
}

void chainsqlParser::Cte_table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCte_table_name(this);
}

void chainsqlParser::Cte_table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCte_table_name(this);
}

chainsqlParser::Cte_table_nameContext* chainsqlParser::cte_table_name() {
  Cte_table_nameContext *_localctx = _tracker.createInstance<Cte_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 44, chainsqlParser::RuleCte_table_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(558);
    table_name();
    setState(570);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::OPEN_PAR) {
      setState(559);
      match(chainsqlParser::OPEN_PAR);
      setState(560);
      column_name();
      setState(565);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == chainsqlParser::COMMA) {
        setState(561);
        match(chainsqlParser::COMMA);
        setState(562);
        column_name();
        setState(567);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(568);
      match(chainsqlParser::CLOSE_PAR);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signed_numberContext ------------------------------------------------------------------

chainsqlParser::Signed_numberContext::Signed_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Signed_numberContext::NUMERIC_LITERAL() {
  return getToken(chainsqlParser::NUMERIC_LITERAL, 0);
}


size_t chainsqlParser::Signed_numberContext::getRuleIndex() const {
  return chainsqlParser::RuleSigned_number;
}

void chainsqlParser::Signed_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSigned_number(this);
}

void chainsqlParser::Signed_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSigned_number(this);
}

chainsqlParser::Signed_numberContext* chainsqlParser::signed_number() {
  Signed_numberContext *_localctx = _tracker.createInstance<Signed_numberContext>(_ctx, getState());
  enterRule(_localctx, 46, chainsqlParser::RuleSigned_number);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == chainsqlParser::PLUS

    || _la == chainsqlParser::MINUS) {
      setState(572);
      _la = _input->LA(1);
      if (!(_la == chainsqlParser::PLUS

      || _la == chainsqlParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(575);
    match(chainsqlParser::NUMERIC_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Literal_valueContext ------------------------------------------------------------------

chainsqlParser::Literal_valueContext::Literal_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Literal_valueContext::NUMERIC_LITERAL() {
  return getToken(chainsqlParser::NUMERIC_LITERAL, 0);
}

tree::TerminalNode* chainsqlParser::Literal_valueContext::STRING_LITERAL() {
  return getToken(chainsqlParser::STRING_LITERAL, 0);
}

tree::TerminalNode* chainsqlParser::Literal_valueContext::BLOB_LITERAL() {
  return getToken(chainsqlParser::BLOB_LITERAL, 0);
}

tree::TerminalNode* chainsqlParser::Literal_valueContext::K_NULL() {
  return getToken(chainsqlParser::K_NULL, 0);
}

tree::TerminalNode* chainsqlParser::Literal_valueContext::K_CURRENT_TIME() {
  return getToken(chainsqlParser::K_CURRENT_TIME, 0);
}

tree::TerminalNode* chainsqlParser::Literal_valueContext::K_CURRENT_DATE() {
  return getToken(chainsqlParser::K_CURRENT_DATE, 0);
}

tree::TerminalNode* chainsqlParser::Literal_valueContext::K_CURRENT_TIMESTAMP() {
  return getToken(chainsqlParser::K_CURRENT_TIMESTAMP, 0);
}


size_t chainsqlParser::Literal_valueContext::getRuleIndex() const {
  return chainsqlParser::RuleLiteral_value;
}

void chainsqlParser::Literal_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral_value(this);
}

void chainsqlParser::Literal_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral_value(this);
}

chainsqlParser::Literal_valueContext* chainsqlParser::literal_value() {
  Literal_valueContext *_localctx = _tracker.createInstance<Literal_valueContext>(_ctx, getState());
  enterRule(_localctx, 48, chainsqlParser::RuleLiteral_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(577);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << chainsqlParser::K_CURRENT_DATE)
      | (1ULL << chainsqlParser::K_CURRENT_TIME)
      | (1ULL << chainsqlParser::K_CURRENT_TIMESTAMP))) != 0) || ((((_la - 104) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 104)) & ((1ULL << (chainsqlParser::K_NULL - 104))
      | (1ULL << (chainsqlParser::NUMERIC_LITERAL - 104))
      | (1ULL << (chainsqlParser::STRING_LITERAL - 104))
      | (1ULL << (chainsqlParser::BLOB_LITERAL - 104)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Error_messageContext ------------------------------------------------------------------

chainsqlParser::Error_messageContext::Error_messageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Error_messageContext::STRING_LITERAL() {
  return getToken(chainsqlParser::STRING_LITERAL, 0);
}


size_t chainsqlParser::Error_messageContext::getRuleIndex() const {
  return chainsqlParser::RuleError_message;
}

void chainsqlParser::Error_messageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterError_message(this);
}

void chainsqlParser::Error_messageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitError_message(this);
}

chainsqlParser::Error_messageContext* chainsqlParser::error_message() {
  Error_messageContext *_localctx = _tracker.createInstance<Error_messageContext>(_ctx, getState());
  enterRule(_localctx, 50, chainsqlParser::RuleError_message);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(579);
    match(chainsqlParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_argumentContext ------------------------------------------------------------------

chainsqlParser::Module_argumentContext::Module_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::ExprContext* chainsqlParser::Module_argumentContext::expr() {
  return getRuleContext<chainsqlParser::ExprContext>(0);
}

chainsqlParser::Column_defContext* chainsqlParser::Module_argumentContext::column_def() {
  return getRuleContext<chainsqlParser::Column_defContext>(0);
}


size_t chainsqlParser::Module_argumentContext::getRuleIndex() const {
  return chainsqlParser::RuleModule_argument;
}

void chainsqlParser::Module_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_argument(this);
}

void chainsqlParser::Module_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_argument(this);
}

chainsqlParser::Module_argumentContext* chainsqlParser::module_argument() {
  Module_argumentContext *_localctx = _tracker.createInstance<Module_argumentContext>(_ctx, getState());
  enterRule(_localctx, 52, chainsqlParser::RuleModule_argument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(583);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(581);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(582);
      column_def();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_aliasContext ------------------------------------------------------------------

chainsqlParser::Column_aliasContext::Column_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Column_aliasContext::IDENTIFIER() {
  return getToken(chainsqlParser::IDENTIFIER, 0);
}

tree::TerminalNode* chainsqlParser::Column_aliasContext::STRING_LITERAL() {
  return getToken(chainsqlParser::STRING_LITERAL, 0);
}


size_t chainsqlParser::Column_aliasContext::getRuleIndex() const {
  return chainsqlParser::RuleColumn_alias;
}

void chainsqlParser::Column_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_alias(this);
}

void chainsqlParser::Column_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_alias(this);
}

chainsqlParser::Column_aliasContext* chainsqlParser::column_alias() {
  Column_aliasContext *_localctx = _tracker.createInstance<Column_aliasContext>(_ctx, getState());
  enterRule(_localctx, 54, chainsqlParser::RuleColumn_alias);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    _la = _input->LA(1);
    if (!(_la == chainsqlParser::IDENTIFIER

    || _la == chainsqlParser::STRING_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

chainsqlParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ABORT() {
  return getToken(chainsqlParser::K_ABORT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ACTION() {
  return getToken(chainsqlParser::K_ACTION, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ADD() {
  return getToken(chainsqlParser::K_ADD, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_AFTER() {
  return getToken(chainsqlParser::K_AFTER, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ALL() {
  return getToken(chainsqlParser::K_ALL, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ALTER() {
  return getToken(chainsqlParser::K_ALTER, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ANALYZE() {
  return getToken(chainsqlParser::K_ANALYZE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_AND() {
  return getToken(chainsqlParser::K_AND, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_AS() {
  return getToken(chainsqlParser::K_AS, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ASC() {
  return getToken(chainsqlParser::K_ASC, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ATTACH() {
  return getToken(chainsqlParser::K_ATTACH, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_AUTOINCREMENT() {
  return getToken(chainsqlParser::K_AUTOINCREMENT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_BEFORE() {
  return getToken(chainsqlParser::K_BEFORE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_BEGIN() {
  return getToken(chainsqlParser::K_BEGIN, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_BETWEEN() {
  return getToken(chainsqlParser::K_BETWEEN, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_BY() {
  return getToken(chainsqlParser::K_BY, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CASCADE() {
  return getToken(chainsqlParser::K_CASCADE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CASE() {
  return getToken(chainsqlParser::K_CASE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CAST() {
  return getToken(chainsqlParser::K_CAST, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CHECK() {
  return getToken(chainsqlParser::K_CHECK, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_COLLATE() {
  return getToken(chainsqlParser::K_COLLATE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_COLUMN() {
  return getToken(chainsqlParser::K_COLUMN, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_COMMIT() {
  return getToken(chainsqlParser::K_COMMIT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CONFLICT() {
  return getToken(chainsqlParser::K_CONFLICT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CONSTRAINT() {
  return getToken(chainsqlParser::K_CONSTRAINT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CREATE() {
  return getToken(chainsqlParser::K_CREATE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CROSS() {
  return getToken(chainsqlParser::K_CROSS, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CURRENT_DATE() {
  return getToken(chainsqlParser::K_CURRENT_DATE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CURRENT_TIME() {
  return getToken(chainsqlParser::K_CURRENT_TIME, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_CURRENT_TIMESTAMP() {
  return getToken(chainsqlParser::K_CURRENT_TIMESTAMP, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_DATABASE() {
  return getToken(chainsqlParser::K_DATABASE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_DEFAULT() {
  return getToken(chainsqlParser::K_DEFAULT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_DEFERRABLE() {
  return getToken(chainsqlParser::K_DEFERRABLE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_DEFERRED() {
  return getToken(chainsqlParser::K_DEFERRED, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_DELETE() {
  return getToken(chainsqlParser::K_DELETE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_DESC() {
  return getToken(chainsqlParser::K_DESC, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_DETACH() {
  return getToken(chainsqlParser::K_DETACH, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_DISTINCT() {
  return getToken(chainsqlParser::K_DISTINCT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_DROP() {
  return getToken(chainsqlParser::K_DROP, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_EACH() {
  return getToken(chainsqlParser::K_EACH, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ELSE() {
  return getToken(chainsqlParser::K_ELSE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_END() {
  return getToken(chainsqlParser::K_END, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ESCAPE() {
  return getToken(chainsqlParser::K_ESCAPE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_EXCEPT() {
  return getToken(chainsqlParser::K_EXCEPT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_EXCLUSIVE() {
  return getToken(chainsqlParser::K_EXCLUSIVE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_EXISTS() {
  return getToken(chainsqlParser::K_EXISTS, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_EXPLAIN() {
  return getToken(chainsqlParser::K_EXPLAIN, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_FAIL() {
  return getToken(chainsqlParser::K_FAIL, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_FOR() {
  return getToken(chainsqlParser::K_FOR, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_FOREIGN() {
  return getToken(chainsqlParser::K_FOREIGN, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_FROM() {
  return getToken(chainsqlParser::K_FROM, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_FULL() {
  return getToken(chainsqlParser::K_FULL, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_GLOB() {
  return getToken(chainsqlParser::K_GLOB, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_GROUP() {
  return getToken(chainsqlParser::K_GROUP, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_HAVING() {
  return getToken(chainsqlParser::K_HAVING, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_IF() {
  return getToken(chainsqlParser::K_IF, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_IGNORE() {
  return getToken(chainsqlParser::K_IGNORE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_IMMEDIATE() {
  return getToken(chainsqlParser::K_IMMEDIATE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_IN() {
  return getToken(chainsqlParser::K_IN, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_INDEX() {
  return getToken(chainsqlParser::K_INDEX, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_INDEXED() {
  return getToken(chainsqlParser::K_INDEXED, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_INITIALLY() {
  return getToken(chainsqlParser::K_INITIALLY, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_INNER() {
  return getToken(chainsqlParser::K_INNER, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_INSERT() {
  return getToken(chainsqlParser::K_INSERT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_INSTEAD() {
  return getToken(chainsqlParser::K_INSTEAD, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_INTERSECT() {
  return getToken(chainsqlParser::K_INTERSECT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_INTO() {
  return getToken(chainsqlParser::K_INTO, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_IS() {
  return getToken(chainsqlParser::K_IS, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ISNULL() {
  return getToken(chainsqlParser::K_ISNULL, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_JOIN() {
  return getToken(chainsqlParser::K_JOIN, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_KEY() {
  return getToken(chainsqlParser::K_KEY, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_LEFT() {
  return getToken(chainsqlParser::K_LEFT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_LIKE() {
  return getToken(chainsqlParser::K_LIKE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_LIMIT() {
  return getToken(chainsqlParser::K_LIMIT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_MATCH() {
  return getToken(chainsqlParser::K_MATCH, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_NATURAL() {
  return getToken(chainsqlParser::K_NATURAL, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_NO() {
  return getToken(chainsqlParser::K_NO, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_NOT() {
  return getToken(chainsqlParser::K_NOT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_NOTNULL() {
  return getToken(chainsqlParser::K_NOTNULL, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_NULL() {
  return getToken(chainsqlParser::K_NULL, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_OF() {
  return getToken(chainsqlParser::K_OF, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_OFFSET() {
  return getToken(chainsqlParser::K_OFFSET, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ON() {
  return getToken(chainsqlParser::K_ON, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_OR() {
  return getToken(chainsqlParser::K_OR, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ORDER() {
  return getToken(chainsqlParser::K_ORDER, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_OUTER() {
  return getToken(chainsqlParser::K_OUTER, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_PLAN() {
  return getToken(chainsqlParser::K_PLAN, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_PRAGMA() {
  return getToken(chainsqlParser::K_PRAGMA, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_PRIMARY() {
  return getToken(chainsqlParser::K_PRIMARY, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_QUERY() {
  return getToken(chainsqlParser::K_QUERY, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_RAISE() {
  return getToken(chainsqlParser::K_RAISE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_RECURSIVE() {
  return getToken(chainsqlParser::K_RECURSIVE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_REFERENCES() {
  return getToken(chainsqlParser::K_REFERENCES, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_REGEXP() {
  return getToken(chainsqlParser::K_REGEXP, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_REINDEX() {
  return getToken(chainsqlParser::K_REINDEX, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_RELEASE() {
  return getToken(chainsqlParser::K_RELEASE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_RENAME() {
  return getToken(chainsqlParser::K_RENAME, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_REPLACE() {
  return getToken(chainsqlParser::K_REPLACE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_RESTRICT() {
  return getToken(chainsqlParser::K_RESTRICT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_RIGHT() {
  return getToken(chainsqlParser::K_RIGHT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ROLLBACK() {
  return getToken(chainsqlParser::K_ROLLBACK, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_ROW() {
  return getToken(chainsqlParser::K_ROW, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_SAVEPOINT() {
  return getToken(chainsqlParser::K_SAVEPOINT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_SELECT() {
  return getToken(chainsqlParser::K_SELECT, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_SET() {
  return getToken(chainsqlParser::K_SET, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_TABLE() {
  return getToken(chainsqlParser::K_TABLE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_SHOW() {
  return getToken(chainsqlParser::K_SHOW, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_TABLES() {
  return getToken(chainsqlParser::K_TABLES, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_TEMP() {
  return getToken(chainsqlParser::K_TEMP, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_TEMPORARY() {
  return getToken(chainsqlParser::K_TEMPORARY, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_THEN() {
  return getToken(chainsqlParser::K_THEN, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_TO() {
  return getToken(chainsqlParser::K_TO, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_TRANSACTION() {
  return getToken(chainsqlParser::K_TRANSACTION, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_TRIGGER() {
  return getToken(chainsqlParser::K_TRIGGER, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_UNION() {
  return getToken(chainsqlParser::K_UNION, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_UNIQUE() {
  return getToken(chainsqlParser::K_UNIQUE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_UPDATE() {
  return getToken(chainsqlParser::K_UPDATE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_USING() {
  return getToken(chainsqlParser::K_USING, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_VACUUM() {
  return getToken(chainsqlParser::K_VACUUM, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_VALUES() {
  return getToken(chainsqlParser::K_VALUES, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_VIEW() {
  return getToken(chainsqlParser::K_VIEW, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_VIRTUAL() {
  return getToken(chainsqlParser::K_VIRTUAL, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_WHEN() {
  return getToken(chainsqlParser::K_WHEN, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_WHERE() {
  return getToken(chainsqlParser::K_WHERE, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_WITH() {
  return getToken(chainsqlParser::K_WITH, 0);
}

tree::TerminalNode* chainsqlParser::KeywordContext::K_WITHOUT() {
  return getToken(chainsqlParser::K_WITHOUT, 0);
}


size_t chainsqlParser::KeywordContext::getRuleIndex() const {
  return chainsqlParser::RuleKeyword;
}

void chainsqlParser::KeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword(this);
}

void chainsqlParser::KeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword(this);
}

chainsqlParser::KeywordContext* chainsqlParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 56, chainsqlParser::RuleKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(587);
    _la = _input->LA(1);
    if (!(((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & ((1ULL << (chainsqlParser::K_ABORT - 25))
      | (1ULL << (chainsqlParser::K_ACTION - 25))
      | (1ULL << (chainsqlParser::K_ADD - 25))
      | (1ULL << (chainsqlParser::K_AFTER - 25))
      | (1ULL << (chainsqlParser::K_ALL - 25))
      | (1ULL << (chainsqlParser::K_ALTER - 25))
      | (1ULL << (chainsqlParser::K_ANALYZE - 25))
      | (1ULL << (chainsqlParser::K_AND - 25))
      | (1ULL << (chainsqlParser::K_AS - 25))
      | (1ULL << (chainsqlParser::K_ASC - 25))
      | (1ULL << (chainsqlParser::K_ATTACH - 25))
      | (1ULL << (chainsqlParser::K_AUTOINCREMENT - 25))
      | (1ULL << (chainsqlParser::K_BEFORE - 25))
      | (1ULL << (chainsqlParser::K_BEGIN - 25))
      | (1ULL << (chainsqlParser::K_BETWEEN - 25))
      | (1ULL << (chainsqlParser::K_BY - 25))
      | (1ULL << (chainsqlParser::K_CASCADE - 25))
      | (1ULL << (chainsqlParser::K_CASE - 25))
      | (1ULL << (chainsqlParser::K_CAST - 25))
      | (1ULL << (chainsqlParser::K_CHECK - 25))
      | (1ULL << (chainsqlParser::K_COLLATE - 25))
      | (1ULL << (chainsqlParser::K_COLUMN - 25))
      | (1ULL << (chainsqlParser::K_COMMIT - 25))
      | (1ULL << (chainsqlParser::K_CONFLICT - 25))
      | (1ULL << (chainsqlParser::K_CONSTRAINT - 25))
      | (1ULL << (chainsqlParser::K_CREATE - 25))
      | (1ULL << (chainsqlParser::K_CROSS - 25))
      | (1ULL << (chainsqlParser::K_CURRENT_DATE - 25))
      | (1ULL << (chainsqlParser::K_CURRENT_TIME - 25))
      | (1ULL << (chainsqlParser::K_CURRENT_TIMESTAMP - 25))
      | (1ULL << (chainsqlParser::K_DATABASE - 25))
      | (1ULL << (chainsqlParser::K_DEFAULT - 25))
      | (1ULL << (chainsqlParser::K_DEFERRABLE - 25))
      | (1ULL << (chainsqlParser::K_DEFERRED - 25))
      | (1ULL << (chainsqlParser::K_DELETE - 25))
      | (1ULL << (chainsqlParser::K_DESC - 25))
      | (1ULL << (chainsqlParser::K_DETACH - 25))
      | (1ULL << (chainsqlParser::K_DISTINCT - 25))
      | (1ULL << (chainsqlParser::K_DROP - 25))
      | (1ULL << (chainsqlParser::K_EACH - 25))
      | (1ULL << (chainsqlParser::K_ELSE - 25))
      | (1ULL << (chainsqlParser::K_END - 25))
      | (1ULL << (chainsqlParser::K_ESCAPE - 25))
      | (1ULL << (chainsqlParser::K_EXCEPT - 25))
      | (1ULL << (chainsqlParser::K_EXCLUSIVE - 25))
      | (1ULL << (chainsqlParser::K_EXISTS - 25))
      | (1ULL << (chainsqlParser::K_EXPLAIN - 25))
      | (1ULL << (chainsqlParser::K_FAIL - 25))
      | (1ULL << (chainsqlParser::K_FOR - 25))
      | (1ULL << (chainsqlParser::K_FOREIGN - 25))
      | (1ULL << (chainsqlParser::K_FROM - 25))
      | (1ULL << (chainsqlParser::K_FULL - 25))
      | (1ULL << (chainsqlParser::K_GLOB - 25))
      | (1ULL << (chainsqlParser::K_GROUP - 25))
      | (1ULL << (chainsqlParser::K_HAVING - 25))
      | (1ULL << (chainsqlParser::K_IF - 25))
      | (1ULL << (chainsqlParser::K_IGNORE - 25))
      | (1ULL << (chainsqlParser::K_IMMEDIATE - 25))
      | (1ULL << (chainsqlParser::K_IN - 25))
      | (1ULL << (chainsqlParser::K_INDEX - 25))
      | (1ULL << (chainsqlParser::K_INDEXED - 25))
      | (1ULL << (chainsqlParser::K_INITIALLY - 25))
      | (1ULL << (chainsqlParser::K_INNER - 25))
      | (1ULL << (chainsqlParser::K_INSERT - 25)))) != 0) || ((((_la - 89) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 89)) & ((1ULL << (chainsqlParser::K_INSTEAD - 89))
      | (1ULL << (chainsqlParser::K_INTERSECT - 89))
      | (1ULL << (chainsqlParser::K_INTO - 89))
      | (1ULL << (chainsqlParser::K_IS - 89))
      | (1ULL << (chainsqlParser::K_ISNULL - 89))
      | (1ULL << (chainsqlParser::K_JOIN - 89))
      | (1ULL << (chainsqlParser::K_KEY - 89))
      | (1ULL << (chainsqlParser::K_LEFT - 89))
      | (1ULL << (chainsqlParser::K_LIKE - 89))
      | (1ULL << (chainsqlParser::K_LIMIT - 89))
      | (1ULL << (chainsqlParser::K_MATCH - 89))
      | (1ULL << (chainsqlParser::K_NATURAL - 89))
      | (1ULL << (chainsqlParser::K_NO - 89))
      | (1ULL << (chainsqlParser::K_NOT - 89))
      | (1ULL << (chainsqlParser::K_NOTNULL - 89))
      | (1ULL << (chainsqlParser::K_NULL - 89))
      | (1ULL << (chainsqlParser::K_OF - 89))
      | (1ULL << (chainsqlParser::K_OFFSET - 89))
      | (1ULL << (chainsqlParser::K_ON - 89))
      | (1ULL << (chainsqlParser::K_OR - 89))
      | (1ULL << (chainsqlParser::K_ORDER - 89))
      | (1ULL << (chainsqlParser::K_OUTER - 89))
      | (1ULL << (chainsqlParser::K_PLAN - 89))
      | (1ULL << (chainsqlParser::K_PRAGMA - 89))
      | (1ULL << (chainsqlParser::K_PRIMARY - 89))
      | (1ULL << (chainsqlParser::K_QUERY - 89))
      | (1ULL << (chainsqlParser::K_RAISE - 89))
      | (1ULL << (chainsqlParser::K_RECURSIVE - 89))
      | (1ULL << (chainsqlParser::K_REFERENCES - 89))
      | (1ULL << (chainsqlParser::K_REGEXP - 89))
      | (1ULL << (chainsqlParser::K_REINDEX - 89))
      | (1ULL << (chainsqlParser::K_RELEASE - 89))
      | (1ULL << (chainsqlParser::K_RENAME - 89))
      | (1ULL << (chainsqlParser::K_REPLACE - 89))
      | (1ULL << (chainsqlParser::K_RESTRICT - 89))
      | (1ULL << (chainsqlParser::K_RIGHT - 89))
      | (1ULL << (chainsqlParser::K_ROLLBACK - 89))
      | (1ULL << (chainsqlParser::K_ROW - 89))
      | (1ULL << (chainsqlParser::K_SAVEPOINT - 89))
      | (1ULL << (chainsqlParser::K_SELECT - 89))
      | (1ULL << (chainsqlParser::K_SET - 89))
      | (1ULL << (chainsqlParser::K_TABLE - 89))
      | (1ULL << (chainsqlParser::K_SHOW - 89))
      | (1ULL << (chainsqlParser::K_TABLES - 89))
      | (1ULL << (chainsqlParser::K_TEMP - 89))
      | (1ULL << (chainsqlParser::K_TEMPORARY - 89))
      | (1ULL << (chainsqlParser::K_THEN - 89))
      | (1ULL << (chainsqlParser::K_TO - 89))
      | (1ULL << (chainsqlParser::K_TRANSACTION - 89))
      | (1ULL << (chainsqlParser::K_TRIGGER - 89))
      | (1ULL << (chainsqlParser::K_UNION - 89))
      | (1ULL << (chainsqlParser::K_UNIQUE - 89))
      | (1ULL << (chainsqlParser::K_UPDATE - 89))
      | (1ULL << (chainsqlParser::K_USING - 89))
      | (1ULL << (chainsqlParser::K_VACUUM - 89))
      | (1ULL << (chainsqlParser::K_VALUES - 89))
      | (1ULL << (chainsqlParser::K_VIEW - 89))
      | (1ULL << (chainsqlParser::K_VIRTUAL - 89))
      | (1ULL << (chainsqlParser::K_WHEN - 89))
      | (1ULL << (chainsqlParser::K_WHERE - 89))
      | (1ULL << (chainsqlParser::K_WITH - 89))
      | (1ULL << (chainsqlParser::K_WITHOUT - 89)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

chainsqlParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::NameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::NameContext::getRuleIndex() const {
  return chainsqlParser::RuleName;
}

void chainsqlParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void chainsqlParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}

chainsqlParser::NameContext* chainsqlParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 58, chainsqlParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(589);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_nameContext ------------------------------------------------------------------

chainsqlParser::Function_nameContext::Function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Function_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Function_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleFunction_name;
}

void chainsqlParser::Function_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_name(this);
}

void chainsqlParser::Function_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_name(this);
}

chainsqlParser::Function_nameContext* chainsqlParser::function_name() {
  Function_nameContext *_localctx = _tracker.createInstance<Function_nameContext>(_ctx, getState());
  enterRule(_localctx, 60, chainsqlParser::RuleFunction_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(591);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_nameContext ------------------------------------------------------------------

chainsqlParser::Table_nameContext::Table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Table_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Table_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleTable_name;
}

void chainsqlParser::Table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_name(this);
}

void chainsqlParser::Table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_name(this);
}

chainsqlParser::Table_nameContext* chainsqlParser::table_name() {
  Table_nameContext *_localctx = _tracker.createInstance<Table_nameContext>(_ctx, getState());
  enterRule(_localctx, 62, chainsqlParser::RuleTable_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(593);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_or_index_nameContext ------------------------------------------------------------------

chainsqlParser::Table_or_index_nameContext::Table_or_index_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Table_or_index_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Table_or_index_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleTable_or_index_name;
}

void chainsqlParser::Table_or_index_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_or_index_name(this);
}

void chainsqlParser::Table_or_index_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_or_index_name(this);
}

chainsqlParser::Table_or_index_nameContext* chainsqlParser::table_or_index_name() {
  Table_or_index_nameContext *_localctx = _tracker.createInstance<Table_or_index_nameContext>(_ctx, getState());
  enterRule(_localctx, 64, chainsqlParser::RuleTable_or_index_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(595);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- New_table_nameContext ------------------------------------------------------------------

chainsqlParser::New_table_nameContext::New_table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::New_table_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::New_table_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleNew_table_name;
}

void chainsqlParser::New_table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNew_table_name(this);
}

void chainsqlParser::New_table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNew_table_name(this);
}

chainsqlParser::New_table_nameContext* chainsqlParser::new_table_name() {
  New_table_nameContext *_localctx = _tracker.createInstance<New_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 66, chainsqlParser::RuleNew_table_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(597);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_nameContext ------------------------------------------------------------------

chainsqlParser::Column_nameContext::Column_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Column_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Column_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleColumn_name;
}

void chainsqlParser::Column_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_name(this);
}

void chainsqlParser::Column_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_name(this);
}

chainsqlParser::Column_nameContext* chainsqlParser::column_name() {
  Column_nameContext *_localctx = _tracker.createInstance<Column_nameContext>(_ctx, getState());
  enterRule(_localctx, 68, chainsqlParser::RuleColumn_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(599);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Collation_nameContext ------------------------------------------------------------------

chainsqlParser::Collation_nameContext::Collation_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Collation_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Collation_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleCollation_name;
}

void chainsqlParser::Collation_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCollation_name(this);
}

void chainsqlParser::Collation_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCollation_name(this);
}

chainsqlParser::Collation_nameContext* chainsqlParser::collation_name() {
  Collation_nameContext *_localctx = _tracker.createInstance<Collation_nameContext>(_ctx, getState());
  enterRule(_localctx, 70, chainsqlParser::RuleCollation_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(601);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Foreign_tableContext ------------------------------------------------------------------

chainsqlParser::Foreign_tableContext::Foreign_tableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Foreign_tableContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Foreign_tableContext::getRuleIndex() const {
  return chainsqlParser::RuleForeign_table;
}

void chainsqlParser::Foreign_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeign_table(this);
}

void chainsqlParser::Foreign_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeign_table(this);
}

chainsqlParser::Foreign_tableContext* chainsqlParser::foreign_table() {
  Foreign_tableContext *_localctx = _tracker.createInstance<Foreign_tableContext>(_ctx, getState());
  enterRule(_localctx, 72, chainsqlParser::RuleForeign_table);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(603);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_nameContext ------------------------------------------------------------------

chainsqlParser::Index_nameContext::Index_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Index_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Index_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleIndex_name;
}

void chainsqlParser::Index_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex_name(this);
}

void chainsqlParser::Index_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex_name(this);
}

chainsqlParser::Index_nameContext* chainsqlParser::index_name() {
  Index_nameContext *_localctx = _tracker.createInstance<Index_nameContext>(_ctx, getState());
  enterRule(_localctx, 74, chainsqlParser::RuleIndex_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(605);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Trigger_nameContext ------------------------------------------------------------------

chainsqlParser::Trigger_nameContext::Trigger_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Trigger_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Trigger_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleTrigger_name;
}

void chainsqlParser::Trigger_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrigger_name(this);
}

void chainsqlParser::Trigger_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrigger_name(this);
}

chainsqlParser::Trigger_nameContext* chainsqlParser::trigger_name() {
  Trigger_nameContext *_localctx = _tracker.createInstance<Trigger_nameContext>(_ctx, getState());
  enterRule(_localctx, 76, chainsqlParser::RuleTrigger_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- View_nameContext ------------------------------------------------------------------

chainsqlParser::View_nameContext::View_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::View_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::View_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleView_name;
}

void chainsqlParser::View_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterView_name(this);
}

void chainsqlParser::View_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitView_name(this);
}

chainsqlParser::View_nameContext* chainsqlParser::view_name() {
  View_nameContext *_localctx = _tracker.createInstance<View_nameContext>(_ctx, getState());
  enterRule(_localctx, 78, chainsqlParser::RuleView_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(609);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_nameContext ------------------------------------------------------------------

chainsqlParser::Module_nameContext::Module_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Module_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Module_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleModule_name;
}

void chainsqlParser::Module_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_name(this);
}

void chainsqlParser::Module_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_name(this);
}

chainsqlParser::Module_nameContext* chainsqlParser::module_name() {
  Module_nameContext *_localctx = _tracker.createInstance<Module_nameContext>(_ctx, getState());
  enterRule(_localctx, 80, chainsqlParser::RuleModule_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(611);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pragma_nameContext ------------------------------------------------------------------

chainsqlParser::Pragma_nameContext::Pragma_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Pragma_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Pragma_nameContext::getRuleIndex() const {
  return chainsqlParser::RulePragma_name;
}

void chainsqlParser::Pragma_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma_name(this);
}

void chainsqlParser::Pragma_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma_name(this);
}

chainsqlParser::Pragma_nameContext* chainsqlParser::pragma_name() {
  Pragma_nameContext *_localctx = _tracker.createInstance<Pragma_nameContext>(_ctx, getState());
  enterRule(_localctx, 82, chainsqlParser::RulePragma_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(613);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Savepoint_nameContext ------------------------------------------------------------------

chainsqlParser::Savepoint_nameContext::Savepoint_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Savepoint_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Savepoint_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleSavepoint_name;
}

void chainsqlParser::Savepoint_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSavepoint_name(this);
}

void chainsqlParser::Savepoint_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSavepoint_name(this);
}

chainsqlParser::Savepoint_nameContext* chainsqlParser::savepoint_name() {
  Savepoint_nameContext *_localctx = _tracker.createInstance<Savepoint_nameContext>(_ctx, getState());
  enterRule(_localctx, 84, chainsqlParser::RuleSavepoint_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(615);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_aliasContext ------------------------------------------------------------------

chainsqlParser::Table_aliasContext::Table_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Table_aliasContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Table_aliasContext::getRuleIndex() const {
  return chainsqlParser::RuleTable_alias;
}

void chainsqlParser::Table_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_alias(this);
}

void chainsqlParser::Table_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_alias(this);
}

chainsqlParser::Table_aliasContext* chainsqlParser::table_alias() {
  Table_aliasContext *_localctx = _tracker.createInstance<Table_aliasContext>(_ctx, getState());
  enterRule(_localctx, 86, chainsqlParser::RuleTable_alias);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(617);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Transaction_nameContext ------------------------------------------------------------------

chainsqlParser::Transaction_nameContext::Transaction_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

chainsqlParser::Any_nameContext* chainsqlParser::Transaction_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Transaction_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleTransaction_name;
}

void chainsqlParser::Transaction_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransaction_name(this);
}

void chainsqlParser::Transaction_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransaction_name(this);
}

chainsqlParser::Transaction_nameContext* chainsqlParser::transaction_name() {
  Transaction_nameContext *_localctx = _tracker.createInstance<Transaction_nameContext>(_ctx, getState());
  enterRule(_localctx, 88, chainsqlParser::RuleTransaction_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(619);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_nameContext ------------------------------------------------------------------

chainsqlParser::Any_nameContext::Any_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* chainsqlParser::Any_nameContext::IDENTIFIER() {
  return getToken(chainsqlParser::IDENTIFIER, 0);
}

chainsqlParser::KeywordContext* chainsqlParser::Any_nameContext::keyword() {
  return getRuleContext<chainsqlParser::KeywordContext>(0);
}

tree::TerminalNode* chainsqlParser::Any_nameContext::STRING_LITERAL() {
  return getToken(chainsqlParser::STRING_LITERAL, 0);
}

chainsqlParser::Any_nameContext* chainsqlParser::Any_nameContext::any_name() {
  return getRuleContext<chainsqlParser::Any_nameContext>(0);
}


size_t chainsqlParser::Any_nameContext::getRuleIndex() const {
  return chainsqlParser::RuleAny_name;
}

void chainsqlParser::Any_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_name(this);
}

void chainsqlParser::Any_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<chainsqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_name(this);
}

chainsqlParser::Any_nameContext* chainsqlParser::any_name() {
  Any_nameContext *_localctx = _tracker.createInstance<Any_nameContext>(_ctx, getState());
  enterRule(_localctx, 90, chainsqlParser::RuleAny_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(628);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case chainsqlParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(621);
        match(chainsqlParser::IDENTIFIER);
        break;
      }

      case chainsqlParser::K_ABORT:
      case chainsqlParser::K_ACTION:
      case chainsqlParser::K_ADD:
      case chainsqlParser::K_AFTER:
      case chainsqlParser::K_ALL:
      case chainsqlParser::K_ALTER:
      case chainsqlParser::K_ANALYZE:
      case chainsqlParser::K_AND:
      case chainsqlParser::K_AS:
      case chainsqlParser::K_ASC:
      case chainsqlParser::K_ATTACH:
      case chainsqlParser::K_AUTOINCREMENT:
      case chainsqlParser::K_BEFORE:
      case chainsqlParser::K_BEGIN:
      case chainsqlParser::K_BETWEEN:
      case chainsqlParser::K_BY:
      case chainsqlParser::K_CASCADE:
      case chainsqlParser::K_CASE:
      case chainsqlParser::K_CAST:
      case chainsqlParser::K_CHECK:
      case chainsqlParser::K_COLLATE:
      case chainsqlParser::K_COLUMN:
      case chainsqlParser::K_COMMIT:
      case chainsqlParser::K_CONFLICT:
      case chainsqlParser::K_CONSTRAINT:
      case chainsqlParser::K_CREATE:
      case chainsqlParser::K_CROSS:
      case chainsqlParser::K_CURRENT_DATE:
      case chainsqlParser::K_CURRENT_TIME:
      case chainsqlParser::K_CURRENT_TIMESTAMP:
      case chainsqlParser::K_DATABASE:
      case chainsqlParser::K_DEFAULT:
      case chainsqlParser::K_DEFERRABLE:
      case chainsqlParser::K_DEFERRED:
      case chainsqlParser::K_DELETE:
      case chainsqlParser::K_DESC:
      case chainsqlParser::K_DETACH:
      case chainsqlParser::K_DISTINCT:
      case chainsqlParser::K_DROP:
      case chainsqlParser::K_EACH:
      case chainsqlParser::K_ELSE:
      case chainsqlParser::K_END:
      case chainsqlParser::K_ESCAPE:
      case chainsqlParser::K_EXCEPT:
      case chainsqlParser::K_EXCLUSIVE:
      case chainsqlParser::K_EXISTS:
      case chainsqlParser::K_EXPLAIN:
      case chainsqlParser::K_FAIL:
      case chainsqlParser::K_FOR:
      case chainsqlParser::K_FOREIGN:
      case chainsqlParser::K_FROM:
      case chainsqlParser::K_FULL:
      case chainsqlParser::K_GLOB:
      case chainsqlParser::K_GROUP:
      case chainsqlParser::K_HAVING:
      case chainsqlParser::K_IF:
      case chainsqlParser::K_IGNORE:
      case chainsqlParser::K_IMMEDIATE:
      case chainsqlParser::K_IN:
      case chainsqlParser::K_INDEX:
      case chainsqlParser::K_INDEXED:
      case chainsqlParser::K_INITIALLY:
      case chainsqlParser::K_INNER:
      case chainsqlParser::K_INSERT:
      case chainsqlParser::K_INSTEAD:
      case chainsqlParser::K_INTERSECT:
      case chainsqlParser::K_INTO:
      case chainsqlParser::K_IS:
      case chainsqlParser::K_ISNULL:
      case chainsqlParser::K_JOIN:
      case chainsqlParser::K_KEY:
      case chainsqlParser::K_LEFT:
      case chainsqlParser::K_LIKE:
      case chainsqlParser::K_LIMIT:
      case chainsqlParser::K_MATCH:
      case chainsqlParser::K_NATURAL:
      case chainsqlParser::K_NO:
      case chainsqlParser::K_NOT:
      case chainsqlParser::K_NOTNULL:
      case chainsqlParser::K_NULL:
      case chainsqlParser::K_OF:
      case chainsqlParser::K_OFFSET:
      case chainsqlParser::K_ON:
      case chainsqlParser::K_OR:
      case chainsqlParser::K_ORDER:
      case chainsqlParser::K_OUTER:
      case chainsqlParser::K_PLAN:
      case chainsqlParser::K_PRAGMA:
      case chainsqlParser::K_PRIMARY:
      case chainsqlParser::K_QUERY:
      case chainsqlParser::K_RAISE:
      case chainsqlParser::K_RECURSIVE:
      case chainsqlParser::K_REFERENCES:
      case chainsqlParser::K_REGEXP:
      case chainsqlParser::K_REINDEX:
      case chainsqlParser::K_RELEASE:
      case chainsqlParser::K_RENAME:
      case chainsqlParser::K_REPLACE:
      case chainsqlParser::K_RESTRICT:
      case chainsqlParser::K_RIGHT:
      case chainsqlParser::K_ROLLBACK:
      case chainsqlParser::K_ROW:
      case chainsqlParser::K_SAVEPOINT:
      case chainsqlParser::K_SELECT:
      case chainsqlParser::K_SET:
      case chainsqlParser::K_TABLE:
      case chainsqlParser::K_SHOW:
      case chainsqlParser::K_TABLES:
      case chainsqlParser::K_TEMP:
      case chainsqlParser::K_TEMPORARY:
      case chainsqlParser::K_THEN:
      case chainsqlParser::K_TO:
      case chainsqlParser::K_TRANSACTION:
      case chainsqlParser::K_TRIGGER:
      case chainsqlParser::K_UNION:
      case chainsqlParser::K_UNIQUE:
      case chainsqlParser::K_UPDATE:
      case chainsqlParser::K_USING:
      case chainsqlParser::K_VACUUM:
      case chainsqlParser::K_VALUES:
      case chainsqlParser::K_VIEW:
      case chainsqlParser::K_VIRTUAL:
      case chainsqlParser::K_WHEN:
      case chainsqlParser::K_WHERE:
      case chainsqlParser::K_WITH:
      case chainsqlParser::K_WITHOUT: {
        enterOuterAlt(_localctx, 2);
        setState(622);
        keyword();
        break;
      }

      case chainsqlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(623);
        match(chainsqlParser::STRING_LITERAL);
        break;
      }

      case chainsqlParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 4);
        setState(624);
        match(chainsqlParser::OPEN_PAR);
        setState(625);
        any_name();
        setState(626);
        match(chainsqlParser::CLOSE_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool chainsqlParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 13: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool chainsqlParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> chainsqlParser::_decisionToDFA;
atn::PredictionContextCache chainsqlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN chainsqlParser::_atn;
std::vector<uint16_t> chainsqlParser::_serializedATN;

std::vector<std::string> chainsqlParser::_ruleNames = {
  "parse", "error", "sql_stmt_list", "sql_stmt", "create_index_stmt", "create_table_stmt", 
  "delete_stmt_limited", "insert_stmt", "select_stmt", "update_stmt_limited", 
  "show_tables_stmt", "column_def", "type_name", "expr", "indexed_column", 
  "qualified_table_name", "ordering_term", "pragma_value", "common_table_expression", 
  "result_column", "table_or_subquery", "select_core", "cte_table_name", 
  "signed_number", "literal_value", "error_message", "module_argument", 
  "column_alias", "keyword", "name", "function_name", "table_name", "table_or_index_name", 
  "new_table_name", "column_name", "collation_name", "foreign_table", "index_name", 
  "trigger_name", "view_name", "module_name", "pragma_name", "savepoint_name", 
  "table_alias", "transaction_name", "any_name"
};

std::vector<std::string> chainsqlParser::_literalNames = {
  "", "';'", "'.'", "'('", "')'", "','", "'='", "'*'", "'+'", "'-'", "'~'", 
  "'||'", "'/'", "'%'", "'<<'", "'>>'", "'&'", "'|'", "'<'", "'<='", "'>'", 
  "'>='", "'=='", "'!='", "'<>'"
};

std::vector<std::string> chainsqlParser::_symbolicNames = {
  "", "SCOL", "DOT", "OPEN_PAR", "CLOSE_PAR", "COMMA", "ASSIGN", "STAR", 
  "PLUS", "MINUS", "TILDE", "PIPE2", "DIV", "MOD", "LT2", "GT2", "AMP", 
  "PIPE", "LT", "LT_EQ", "GT", "GT_EQ", "EQ", "NOT_EQ1", "NOT_EQ2", "K_ABORT", 
  "K_ACTION", "K_ADD", "K_AFTER", "K_ALL", "K_ALTER", "K_ANALYZE", "K_AND", 
  "K_AS", "K_ASC", "K_ATTACH", "K_AUTOINCREMENT", "K_BEFORE", "K_BEGIN", 
  "K_BETWEEN", "K_BY", "K_CASCADE", "K_CASE", "K_CAST", "K_CHECK", "K_COLLATE", 
  "K_COLUMN", "K_COMMIT", "K_CONFLICT", "K_CONSTRAINT", "K_CREATE", "K_CROSS", 
  "K_CURRENT_DATE", "K_CURRENT_TIME", "K_CURRENT_TIMESTAMP", "K_DATABASE", 
  "K_DEFAULT", "K_DEFERRABLE", "K_DEFERRED", "K_DELETE", "K_DESC", "K_DETACH", 
  "K_DISTINCT", "K_DROP", "K_EACH", "K_ELSE", "K_END", "K_ESCAPE", "K_EXCEPT", 
  "K_EXCLUSIVE", "K_EXISTS", "K_EXPLAIN", "K_FAIL", "K_FOR", "K_FOREIGN", 
  "K_FROM", "K_FULL", "K_GLOB", "K_GROUP", "K_HAVING", "K_IF", "K_IGNORE", 
  "K_IMMEDIATE", "K_IN", "K_INDEX", "K_INDEXED", "K_INITIALLY", "K_INNER", 
  "K_INSERT", "K_INSTEAD", "K_INTERSECT", "K_INTO", "K_IS", "K_ISNULL", 
  "K_JOIN", "K_KEY", "K_LEFT", "K_LIKE", "K_LIMIT", "K_MATCH", "K_NATURAL", 
  "K_NO", "K_NOT", "K_NOTNULL", "K_NULL", "K_OF", "K_OFFSET", "K_ON", "K_OR", 
  "K_ORDER", "K_OUTER", "K_PLAN", "K_PRAGMA", "K_PRIMARY", "K_QUERY", "K_RAISE", 
  "K_RECURSIVE", "K_REFERENCES", "K_REGEXP", "K_REINDEX", "K_RELEASE", "K_RENAME", 
  "K_REPLACE", "K_RESTRICT", "K_RIGHT", "K_ROLLBACK", "K_ROW", "K_SAVEPOINT", 
  "K_SELECT", "K_SET", "K_TABLE", "K_SHOW", "K_TABLES", "K_TEMP", "K_TEMPORARY", 
  "K_THEN", "K_TO", "K_TRANSACTION", "K_TRIGGER", "K_UNION", "K_UNIQUE", 
  "K_UPDATE", "K_USING", "K_VACUUM", "K_VALUES", "K_VIEW", "K_VIRTUAL", 
  "K_WHEN", "K_WHERE", "K_WITH", "K_WITHOUT", "IDENTIFIER", "NUMERIC_LITERAL", 
  "BIND_PARAMETER", "STRING_LITERAL", "BLOB_LITERAL", "SINGLE_LINE_COMMENT", 
  "MULTILINE_COMMENT", "SPACES", "UNEXPECTED_CHAR"
};

dfa::Vocabulary chainsqlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> chainsqlParser::_tokenNames;

chainsqlParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xa1, 0x279, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x61, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x64, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x4, 0x7, 0x4, 0x6c, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x6f, 0xb, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0x73, 0xa, 0x4, 0xd, 0x4, 0xe, 0x4, 0x74, 
    0x3, 0x4, 0x7, 0x4, 0x78, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x7b, 0xb, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x7e, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x81, 0xb, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x8a, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x8e, 0xa, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x7, 0x6, 0x98, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x9b, 0xb, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0xa6, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xa9, 
    0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0xb2, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x7, 0x8, 0xb9, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xbc, 0xb, 
    0x8, 0x5, 0x8, 0xbe, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 
    0xca, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xcd, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xd6, 0xa, 
    0x9, 0xc, 0x9, 0xe, 0x9, 0xd9, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xe1, 0xa, 0x9, 0xc, 0x9, 0xe, 
    0x9, 0xe4, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xe8, 0xa, 0x9, 0xc, 
    0x9, 0xe, 0x9, 0xeb, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xef, 0xa, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xf4, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0xf7, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 
    0xa, 0xfd, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x100, 0xb, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x5, 0xa, 0x104, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x7, 0xa, 0x10b, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x10e, 
    0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x112, 0xa, 0xa, 0x5, 0xa, 0x114, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0x11b, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x11e, 0xb, 0xa, 0x5, 0xa, 0x120, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x126, 0xa, 
    0xa, 0x5, 0xa, 0x128, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0x135, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x138, 0xb, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0x13c, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x143, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x146, 
    0xb, 0xb, 0x5, 0xb, 0x148, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x6, 
    0xe, 0x154, 0xa, 0xe, 0xd, 0xe, 0xe, 0xe, 0x155, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x5, 0xe, 0x162, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0x169, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x5, 0xf, 0x16f, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 
    0xf, 0x174, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x177, 0xb, 0xf, 0x3, 0xf, 
    0x5, 0xf, 0x17a, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0x182, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0x194, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1a0, 0xa, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0x1a8, 0xa, 0xf, 0x7, 0xf, 0x1aa, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1ad, 
    0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x1b1, 0xa, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x1b7, 0xa, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x1bc, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x1c3, 0xa, 0x14, 0xc, 0x14, 
    0xe, 0x14, 0x1c6, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x1ca, 
    0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x1dc, 0xa, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0x1df, 0xa, 0x15, 0x5, 0x15, 0x1e1, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x1e5, 0xa, 0x16, 0x3, 0x16, 0x5, 0x16, 
    0x1e8, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1ec, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x1f1, 0xa, 0x17, 0xc, 0x17, 
    0xe, 0x17, 0x1f4, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x7, 0x17, 0x1fa, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x1fd, 0xb, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x201, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x208, 0xa, 0x17, 0xc, 0x17, 
    0xe, 0x17, 0x20b, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x20f, 
    0xa, 0x17, 0x5, 0x17, 0x211, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x218, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 
    0x21b, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x7, 0x17, 0x223, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x226, 
    0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x22a, 0xa, 0x17, 0xc, 0x17, 
    0xe, 0x17, 0x22d, 0xb, 0x17, 0x5, 0x17, 0x22f, 0xa, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x236, 0xa, 0x18, 
    0xc, 0x18, 0xe, 0x18, 0x239, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
    0x23d, 0xa, 0x18, 0x3, 0x19, 0x5, 0x19, 0x240, 0xa, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 
    0x1c, 0x5, 0x1c, 0x24a, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x5, 0x2f, 0x277, 0xa, 0x2f, 0x3, 0x2f, 0x2, 0x3, 0x1c, 0x30, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
    0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x2, 0x9, 0x4, 
    0x2, 0x1f, 0x1f, 0x40, 0x40, 0x3, 0x2, 0x14, 0x17, 0x4, 0x2, 0x24, 0x24, 
    0x3e, 0x3e, 0x3, 0x2, 0xa, 0xb, 0x6, 0x2, 0x36, 0x38, 0x6a, 0x6a, 0x9a, 
    0x9a, 0x9c, 0x9d, 0x4, 0x2, 0x99, 0x99, 0x9c, 0x9c, 0x3, 0x2, 0x1b, 
    0x98, 0x2, 0x2ac, 0x2, 0x62, 0x3, 0x2, 0x2, 0x2, 0x4, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x8b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xe, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x12, 0xec, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x129, 0x3, 0x2, 0x2, 0x2, 0x16, 0x14c, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x153, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x181, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1ae, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x22, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x1bb, 0x3, 0x2, 0x2, 0x2, 0x26, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x28, 0x1e0, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x22e, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x230, 0x3, 0x2, 0x2, 0x2, 0x30, 0x23f, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x243, 0x3, 0x2, 0x2, 0x2, 0x34, 0x245, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x249, 0x3, 0x2, 0x2, 0x2, 0x38, 0x24b, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x251, 0x3, 0x2, 0x2, 0x2, 0x40, 0x253, 0x3, 0x2, 0x2, 0x2, 0x42, 0x255, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x257, 0x3, 0x2, 0x2, 0x2, 0x46, 0x259, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x25d, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x261, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x263, 0x3, 0x2, 0x2, 0x2, 0x52, 0x265, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x267, 0x3, 0x2, 0x2, 0x2, 0x56, 0x269, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x26b, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x276, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x5, 0x6, 0x4, 0x2, 0x5f, 0x61, 0x5, 
    0x4, 0x3, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x64, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 0x2, 0x2, 0x3, 0x66, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0xa1, 0x2, 0x2, 0x68, 0x69, 
    0x8, 0x3, 0x1, 0x2, 0x69, 0x5, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6c, 0x7, 
    0x3, 0x2, 0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x79, 0x5, 0x8, 0x5, 0x2, 0x71, 0x73, 0x7, 0x3, 0x2, 0x2, 0x72, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x78, 0x5, 0x8, 0x5, 0x2, 0x77, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 0x7, 0x3, 0x2, 0x2, 0x7d, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0x8a, 0x5, 0xa, 
    0x6, 0x2, 0x83, 0x8a, 0x5, 0xc, 0x7, 0x2, 0x84, 0x8a, 0x5, 0xe, 0x8, 
    0x2, 0x85, 0x8a, 0x5, 0x10, 0x9, 0x2, 0x86, 0x8a, 0x5, 0x12, 0xa, 0x2, 
    0x87, 0x8a, 0x5, 0x14, 0xb, 0x2, 0x88, 0x8a, 0x5, 0x16, 0xc, 0x2, 0x89, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0x89, 0x83, 0x3, 0x2, 0x2, 0x2, 0x89, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x85, 0x3, 0x2, 0x2, 0x2, 0x89, 0x86, 0x3, 
    0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x88, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8d, 0x7, 0x34, 0x2, 
    0x2, 0x8c, 0x8e, 0x7, 0x8e, 0x2, 0x2, 0x8d, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x90, 0x7, 0x56, 0x2, 0x2, 0x90, 0x91, 0x5, 0x4c, 0x27, 0x2, 0x91, 0x92, 
    0x7, 0x6d, 0x2, 0x2, 0x92, 0x93, 0x5, 0x40, 0x21, 0x2, 0x93, 0x94, 0x7, 
    0x5, 0x2, 0x2, 0x94, 0x99, 0x5, 0x1e, 0x10, 0x2, 0x95, 0x96, 0x7, 0x7, 
    0x2, 0x2, 0x96, 0x98, 0x5, 0x1e, 0x10, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x6, 0x2, 0x2, 0x9d, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x34, 0x2, 0x2, 0x9f, 0xa0, 0x7, 
    0x84, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x40, 0x21, 0x2, 0xa1, 0xa2, 0x7, 0x5, 
    0x2, 0x2, 0xa2, 0xa7, 0x5, 0x18, 0xd, 0x2, 0xa3, 0xa4, 0x7, 0x7, 0x2, 
    0x2, 0xa4, 0xa6, 0x5, 0x18, 0xd, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x6, 0x2, 0x2, 0xab, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xad, 0x7, 0x3d, 0x2, 0x2, 0xad, 0xae, 0x7, 0x4d, 
    0x2, 0x2, 0xae, 0xb1, 0x5, 0x20, 0x11, 0x2, 0xaf, 0xb0, 0x7, 0x96, 0x2, 
    0x2, 0xb0, 0xb2, 0x5, 0x1c, 0xf, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xb4, 0x7, 0x6f, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x2a, 0x2, 0x2, 0xb5, 0xba, 
    0x5, 0x22, 0x12, 0x2, 0xb6, 0xb7, 0x7, 0x7, 0x2, 0x2, 0xb7, 0xb9, 0x5, 
    0x22, 0x12, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbc, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0xbb, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 
    0xbd, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x64, 0x2, 0x2, 0xc0, 0xc1, 
    0x5, 0x1c, 0xf, 0x2, 0xc1, 0xf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x7, 
    0x5a, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x5d, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x40, 
    0x21, 0x2, 0xc5, 0xc6, 0x7, 0x5, 0x2, 0x2, 0xc6, 0xcb, 0x5, 0x46, 0x24, 
    0x2, 0xc7, 0xc8, 0x7, 0x7, 0x2, 0x2, 0xc8, 0xca, 0x5, 0x46, 0x24, 0x2, 
    0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x7, 
    0x6, 0x2, 0x2, 0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x92, 
    0x2, 0x2, 0xd1, 0xd2, 0x7, 0x5, 0x2, 0x2, 0xd2, 0xd7, 0x5, 0x1c, 0xf, 
    0x2, 0xd3, 0xd4, 0x7, 0x7, 0x2, 0x2, 0xd4, 0xd6, 0x5, 0x1c, 0xf, 0x2, 
    0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 
    0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xe9, 0x7, 
    0x6, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x7, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x5, 
    0x2, 0x2, 0xdd, 0xe2, 0x5, 0x1c, 0xf, 0x2, 0xde, 0xdf, 0x7, 0x7, 0x2, 
    0x2, 0xdf, 0xe1, 0x5, 0x1c, 0xf, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 
    0xe1, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 
    0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x6, 0x2, 0x2, 0xe6, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xe7, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xeb, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0x11, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xee, 0x7, 0x82, 0x2, 0x2, 0xed, 0xef, 0x9, 0x2, 0x2, 0x2, 0xee, 
    0xed, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 
    0x3, 0x2, 0x2, 0x2, 0xf0, 0xf5, 0x5, 0x28, 0x15, 0x2, 0xf1, 0xf2, 0x7, 
    0x7, 0x2, 0x2, 0xf2, 0xf4, 0x5, 0x28, 0x15, 0x2, 0xf3, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xf4, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 
    0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x4d, 0x2, 0x2, 0xf9, 
    0xfe, 0x5, 0x2a, 0x16, 0x2, 0xfa, 0xfb, 0x7, 0x7, 0x2, 0x2, 0xfb, 0xfd, 
    0x5, 0x2a, 0x16, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 
    0x2, 0x2, 0xff, 0x103, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0x102, 0x7, 0x96, 0x2, 0x2, 0x102, 0x104, 0x5, 0x1c, 0xf, 
    0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 
    0x2, 0x104, 0x113, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x50, 0x2, 
    0x2, 0x106, 0x107, 0x7, 0x2a, 0x2, 0x2, 0x107, 0x10c, 0x5, 0x1c, 0xf, 
    0x2, 0x108, 0x109, 0x7, 0x7, 0x2, 0x2, 0x109, 0x10b, 0x5, 0x1c, 0xf, 
    0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10e, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x3, 0x2, 0x2, 
    0x2, 0x10d, 0x111, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 
    0x2, 0x10f, 0x110, 0x7, 0x51, 0x2, 0x2, 0x110, 0x112, 0x5, 0x1c, 0xf, 
    0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0x114, 0x3, 0x2, 0x2, 0x2, 0x113, 0x105, 0x3, 0x2, 0x2, 
    0x2, 0x113, 0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 0x11f, 0x3, 0x2, 0x2, 
    0x2, 0x115, 0x116, 0x7, 0x6f, 0x2, 0x2, 0x116, 0x117, 0x7, 0x2a, 0x2, 
    0x2, 0x117, 0x11c, 0x5, 0x22, 0x12, 0x2, 0x118, 0x119, 0x7, 0x7, 0x2, 
    0x2, 0x119, 0x11b, 0x5, 0x22, 0x12, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x120, 0x3, 0x2, 0x2, 
    0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x115, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 0x120, 0x127, 0x3, 0x2, 0x2, 
    0x2, 0x121, 0x122, 0x7, 0x64, 0x2, 0x2, 0x122, 0x125, 0x5, 0x1c, 0xf, 
    0x2, 0x123, 0x124, 0x7, 0x6c, 0x2, 0x2, 0x124, 0x126, 0x5, 0x1c, 0xf, 
    0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x128, 0x3, 0x2, 0x2, 0x2, 0x127, 0x121, 0x3, 0x2, 0x2, 
    0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x129, 0x12a, 0x7, 0x8f, 0x2, 0x2, 0x12a, 0x12b, 0x5, 0x20, 0x11, 0x2, 
    0x12b, 0x12c, 0x7, 0x83, 0x2, 0x2, 0x12c, 0x12d, 0x5, 0x46, 0x24, 0x2, 
    0x12d, 0x12e, 0x7, 0x8, 0x2, 0x2, 0x12e, 0x136, 0x5, 0x1c, 0xf, 0x2, 
    0x12f, 0x130, 0x7, 0x7, 0x2, 0x2, 0x130, 0x131, 0x5, 0x46, 0x24, 0x2, 
    0x131, 0x132, 0x7, 0x8, 0x2, 0x2, 0x132, 0x133, 0x5, 0x1c, 0xf, 0x2, 
    0x133, 0x135, 0x3, 0x2, 0x2, 0x2, 0x134, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x135, 0x138, 0x3, 0x2, 0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 
    0x136, 0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13b, 0x3, 0x2, 0x2, 0x2, 
    0x138, 0x136, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x7, 0x96, 0x2, 0x2, 
    0x13a, 0x13c, 0x5, 0x1c, 0xf, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x147, 0x3, 0x2, 0x2, 0x2, 
    0x13d, 0x13e, 0x7, 0x6f, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x2a, 0x2, 0x2, 
    0x13f, 0x144, 0x5, 0x22, 0x12, 0x2, 0x140, 0x141, 0x7, 0x7, 0x2, 0x2, 
    0x141, 0x143, 0x5, 0x22, 0x12, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 
    0x143, 0x146, 0x3, 0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 
    0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x148, 0x3, 0x2, 0x2, 0x2, 
    0x146, 0x144, 0x3, 0x2, 0x2, 0x2, 0x147, 0x13d, 0x3, 0x2, 0x2, 0x2, 
    0x147, 0x148, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 0x2, 
    0x149, 0x14a, 0x7, 0x64, 0x2, 0x2, 0x14a, 0x14b, 0x5, 0x1c, 0xf, 0x2, 
    0x14b, 0x15, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0x85, 0x2, 0x2, 
    0x14d, 0x14e, 0x7, 0x86, 0x2, 0x2, 0x14e, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x14f, 0x150, 0x5, 0x46, 0x24, 0x2, 0x150, 0x151, 0x5, 0x1a, 0xe, 0x2, 
    0x151, 0x19, 0x3, 0x2, 0x2, 0x2, 0x152, 0x154, 0x5, 0x3c, 0x1f, 0x2, 
    0x153, 0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 
    0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 
    0x156, 0x161, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 0x7, 0x5, 0x2, 0x2, 
    0x158, 0x159, 0x5, 0x30, 0x19, 0x2, 0x159, 0x15a, 0x7, 0x6, 0x2, 0x2, 
    0x15a, 0x162, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x7, 0x5, 0x2, 0x2, 
    0x15c, 0x15d, 0x5, 0x30, 0x19, 0x2, 0x15d, 0x15e, 0x7, 0x7, 0x2, 0x2, 
    0x15e, 0x15f, 0x5, 0x30, 0x19, 0x2, 0x15f, 0x160, 0x7, 0x6, 0x2, 0x2, 
    0x160, 0x162, 0x3, 0x2, 0x2, 0x2, 0x161, 0x157, 0x3, 0x2, 0x2, 0x2, 
    0x161, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x3, 0x2, 0x2, 0x2, 
    0x162, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x8, 0xf, 0x1, 0x2, 0x164, 
    0x182, 0x5, 0x32, 0x1a, 0x2, 0x165, 0x166, 0x5, 0x40, 0x21, 0x2, 0x166, 
    0x167, 0x7, 0x4, 0x2, 0x2, 0x167, 0x169, 0x3, 0x2, 0x2, 0x2, 0x168, 
    0x165, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 
    0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x182, 0x5, 0x46, 0x24, 0x2, 0x16b, 
    0x16c, 0x5, 0x3e, 0x20, 0x2, 0x16c, 0x179, 0x7, 0x5, 0x2, 0x2, 0x16d, 
    0x16f, 0x7, 0x40, 0x2, 0x2, 0x16e, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16e, 
    0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 
    0x175, 0x5, 0x1c, 0xf, 0x2, 0x171, 0x172, 0x7, 0x7, 0x2, 0x2, 0x172, 
    0x174, 0x5, 0x1c, 0xf, 0x2, 0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x174, 
    0x177, 0x3, 0x2, 0x2, 0x2, 0x175, 0x173, 0x3, 0x2, 0x2, 0x2, 0x175, 
    0x176, 0x3, 0x2, 0x2, 0x2, 0x176, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x177, 
    0x175, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17a, 0x7, 0x9, 0x2, 0x2, 0x179, 
    0x16e, 0x3, 0x2, 0x2, 0x2, 0x179, 0x178, 0x3, 0x2, 0x2, 0x2, 0x179, 
    0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17b, 
    0x17c, 0x7, 0x6, 0x2, 0x2, 0x17c, 0x182, 0x3, 0x2, 0x2, 0x2, 0x17d, 
    0x17e, 0x7, 0x5, 0x2, 0x2, 0x17e, 0x17f, 0x5, 0x1c, 0xf, 0x2, 0x17f, 
    0x180, 0x7, 0x6, 0x2, 0x2, 0x180, 0x182, 0x3, 0x2, 0x2, 0x2, 0x181, 
    0x163, 0x3, 0x2, 0x2, 0x2, 0x181, 0x168, 0x3, 0x2, 0x2, 0x2, 0x181, 
    0x16b, 0x3, 0x2, 0x2, 0x2, 0x181, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x182, 
    0x1ab, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0xc, 0x9, 0x2, 0x2, 0x184, 
    0x185, 0x9, 0x3, 0x2, 0x2, 0x185, 0x1aa, 0x5, 0x1c, 0xf, 0xa, 0x186, 
    0x193, 0xc, 0x8, 0x2, 0x2, 0x187, 0x194, 0x7, 0x8, 0x2, 0x2, 0x188, 
    0x194, 0x7, 0x18, 0x2, 0x2, 0x189, 0x194, 0x7, 0x19, 0x2, 0x2, 0x18a, 
    0x194, 0x7, 0x1a, 0x2, 0x2, 0x18b, 0x194, 0x7, 0x5e, 0x2, 0x2, 0x18c, 
    0x18d, 0x7, 0x5e, 0x2, 0x2, 0x18d, 0x194, 0x7, 0x68, 0x2, 0x2, 0x18e, 
    0x194, 0x7, 0x55, 0x2, 0x2, 0x18f, 0x194, 0x7, 0x63, 0x2, 0x2, 0x190, 
    0x194, 0x7, 0x4f, 0x2, 0x2, 0x191, 0x194, 0x7, 0x65, 0x2, 0x2, 0x192, 
    0x194, 0x7, 0x78, 0x2, 0x2, 0x193, 0x187, 0x3, 0x2, 0x2, 0x2, 0x193, 
    0x188, 0x3, 0x2, 0x2, 0x2, 0x193, 0x189, 0x3, 0x2, 0x2, 0x2, 0x193, 
    0x18a, 0x3, 0x2, 0x2, 0x2, 0x193, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x193, 
    0x18c, 0x3, 0x2, 0x2, 0x2, 0x193, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x193, 
    0x18f, 0x3, 0x2, 0x2, 0x2, 0x193, 0x190, 0x3, 0x2, 0x2, 0x2, 0x193, 
    0x191, 0x3, 0x2, 0x2, 0x2, 0x193, 0x192, 0x3, 0x2, 0x2, 0x2, 0x194, 
    0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x1aa, 0x5, 0x1c, 0xf, 0x9, 0x196, 
    0x197, 0xc, 0x7, 0x2, 0x2, 0x197, 0x198, 0x7, 0x22, 0x2, 0x2, 0x198, 
    0x1aa, 0x5, 0x1c, 0xf, 0x8, 0x199, 0x19a, 0xc, 0x6, 0x2, 0x2, 0x19a, 
    0x19b, 0x7, 0x6e, 0x2, 0x2, 0x19b, 0x1aa, 0x5, 0x1c, 0xf, 0x7, 0x19c, 
    0x19d, 0xc, 0x4, 0x2, 0x2, 0x19d, 0x19f, 0x7, 0x5e, 0x2, 0x2, 0x19e, 
    0x1a0, 0x7, 0x68, 0x2, 0x2, 0x19f, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19f, 
    0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a1, 
    0x1aa, 0x5, 0x1c, 0xf, 0x5, 0x1a2, 0x1a7, 0xc, 0x5, 0x2, 0x2, 0x1a3, 
    0x1a8, 0x7, 0x5f, 0x2, 0x2, 0x1a4, 0x1a8, 0x7, 0x69, 0x2, 0x2, 0x1a5, 
    0x1a6, 0x7, 0x68, 0x2, 0x2, 0x1a6, 0x1a8, 0x7, 0x6a, 0x2, 0x2, 0x1a7, 
    0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a7, 
    0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
    0x183, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x186, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
    0x196, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x199, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
    0x19c, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1aa, 
    0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1ab, 
    0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ab, 
    0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b0, 0x5, 0x46, 0x24, 0x2, 0x1af, 0x1b1, 
    0x9, 0x4, 0x2, 0x2, 0x1b0, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 
    0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x5, 
    0x40, 0x21, 0x2, 0x1b3, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 
    0x1c, 0xf, 0x2, 0x1b5, 0x1b7, 0x9, 0x4, 0x2, 0x2, 0x1b6, 0x1b5, 0x3, 
    0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x1b8, 0x1bc, 0x5, 0x30, 0x19, 0x2, 0x1b9, 0x1bc, 0x5, 0x3c, 
    0x1f, 0x2, 0x1ba, 0x1bc, 0x7, 0x9c, 0x2, 0x2, 0x1bb, 0x1b8, 0x3, 0x2, 
    0x2, 0x2, 0x1bb, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1ba, 0x3, 0x2, 
    0x2, 0x2, 0x1bc, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1c9, 0x5, 0x40, 
    0x21, 0x2, 0x1be, 0x1bf, 0x7, 0x5, 0x2, 0x2, 0x1bf, 0x1c4, 0x5, 0x46, 
    0x24, 0x2, 0x1c0, 0x1c1, 0x7, 0x7, 0x2, 0x2, 0x1c1, 0x1c3, 0x5, 0x46, 
    0x24, 0x2, 0x1c2, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c6, 0x3, 0x2, 
    0x2, 0x2, 0x1c4, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 
    0x2, 0x2, 0x1c5, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c4, 0x3, 0x2, 
    0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x6, 0x2, 0x2, 0x1c8, 0x1ca, 0x3, 0x2, 
    0x2, 0x2, 0x1c9, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x3, 0x2, 
    0x2, 0x2, 0x1ca, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x7, 0x23, 
    0x2, 0x2, 0x1cc, 0x1cd, 0x7, 0x5, 0x2, 0x2, 0x1cd, 0x1ce, 0x5, 0x12, 
    0xa, 0x2, 0x1ce, 0x1cf, 0x7, 0x6, 0x2, 0x2, 0x1cf, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x1d0, 0x1e1, 0x7, 0x9, 0x2, 0x2, 0x1d1, 0x1d2, 0x5, 0x40, 0x21, 
    0x2, 0x1d2, 0x1d3, 0x7, 0x4, 0x2, 0x2, 0x1d3, 0x1d4, 0x7, 0x9, 0x2, 
    0x2, 0x1d4, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x5, 0x40, 0x21, 
    0x2, 0x1d6, 0x1d7, 0x7, 0x4, 0x2, 0x2, 0x1d7, 0x1d8, 0x5, 0x46, 0x24, 
    0x2, 0x1d8, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1de, 0x5, 0x1c, 0xf, 
    0x2, 0x1da, 0x1dc, 0x7, 0x23, 0x2, 0x2, 0x1db, 0x1da, 0x3, 0x2, 0x2, 
    0x2, 0x1db, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1dd, 0x3, 0x2, 0x2, 
    0x2, 0x1dd, 0x1df, 0x5, 0x38, 0x1d, 0x2, 0x1de, 0x1db, 0x3, 0x2, 0x2, 
    0x2, 0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e1, 0x3, 0x2, 0x2, 
    0x2, 0x1e0, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1d1, 0x3, 0x2, 0x2, 
    0x2, 0x1e0, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1d9, 0x3, 0x2, 0x2, 
    0x2, 0x1e1, 0x29, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e7, 0x5, 0x40, 0x21, 
    0x2, 0x1e3, 0x1e5, 0x7, 0x23, 0x2, 0x2, 0x1e4, 0x1e3, 0x3, 0x2, 0x2, 
    0x2, 0x1e4, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e6, 0x3, 0x2, 0x2, 
    0x2, 0x1e6, 0x1e8, 0x5, 0x58, 0x2d, 0x2, 0x1e7, 0x1e4, 0x3, 0x2, 0x2, 
    0x2, 0x1e7, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x1e9, 0x1eb, 0x7, 0x82, 0x2, 0x2, 0x1ea, 0x1ec, 0x9, 0x2, 0x2, 0x2, 
    0x1eb, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x3, 0x2, 0x2, 0x2, 
    0x1ec, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1f2, 0x5, 0x28, 0x15, 0x2, 
    0x1ee, 0x1ef, 0x7, 0x7, 0x2, 0x2, 0x1ef, 0x1f1, 0x5, 0x28, 0x15, 0x2, 
    0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f4, 0x3, 0x2, 0x2, 0x2, 
    0x1f2, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x3, 0x2, 0x2, 0x2, 
    0x1f3, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f2, 0x3, 0x2, 0x2, 0x2, 
    0x1f5, 0x1f6, 0x7, 0x4d, 0x2, 0x2, 0x1f6, 0x1fb, 0x5, 0x2a, 0x16, 0x2, 
    0x1f7, 0x1f8, 0x7, 0x7, 0x2, 0x2, 0x1f8, 0x1fa, 0x5, 0x2a, 0x16, 0x2, 
    0x1f9, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fd, 0x3, 0x2, 0x2, 0x2, 
    0x1fb, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 
    0x1fc, 0x200, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x1fe, 0x1ff, 0x7, 0x96, 0x2, 0x2, 0x1ff, 0x201, 0x5, 0x1c, 0xf, 0x2, 
    0x200, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 0x2, 
    0x201, 0x210, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 0x7, 0x50, 0x2, 0x2, 
    0x203, 0x204, 0x7, 0x2a, 0x2, 0x2, 0x204, 0x209, 0x5, 0x1c, 0xf, 0x2, 
    0x205, 0x206, 0x7, 0x7, 0x2, 0x2, 0x206, 0x208, 0x5, 0x1c, 0xf, 0x2, 
    0x207, 0x205, 0x3, 0x2, 0x2, 0x2, 0x208, 0x20b, 0x3, 0x2, 0x2, 0x2, 
    0x209, 0x207, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x20a, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x209, 0x3, 0x2, 0x2, 0x2, 
    0x20c, 0x20d, 0x7, 0x51, 0x2, 0x2, 0x20d, 0x20f, 0x5, 0x1c, 0xf, 0x2, 
    0x20e, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20f, 0x3, 0x2, 0x2, 0x2, 
    0x20f, 0x211, 0x3, 0x2, 0x2, 0x2, 0x210, 0x202, 0x3, 0x2, 0x2, 0x2, 
    0x210, 0x211, 0x3, 0x2, 0x2, 0x2, 0x211, 0x22f, 0x3, 0x2, 0x2, 0x2, 
    0x212, 0x213, 0x7, 0x92, 0x2, 0x2, 0x213, 0x214, 0x7, 0x5, 0x2, 0x2, 
    0x214, 0x219, 0x5, 0x1c, 0xf, 0x2, 0x215, 0x216, 0x7, 0x7, 0x2, 0x2, 
    0x216, 0x218, 0x5, 0x1c, 0xf, 0x2, 0x217, 0x215, 0x3, 0x2, 0x2, 0x2, 
    0x218, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 
    0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21c, 0x3, 0x2, 0x2, 0x2, 
    0x21b, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x22b, 0x7, 0x6, 0x2, 0x2, 
    0x21d, 0x21e, 0x7, 0x7, 0x2, 0x2, 0x21e, 0x21f, 0x7, 0x5, 0x2, 0x2, 
    0x21f, 0x224, 0x5, 0x1c, 0xf, 0x2, 0x220, 0x221, 0x7, 0x7, 0x2, 0x2, 
    0x221, 0x223, 0x5, 0x1c, 0xf, 0x2, 0x222, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x226, 0x3, 0x2, 0x2, 0x2, 0x224, 0x222, 0x3, 0x2, 0x2, 0x2, 
    0x224, 0x225, 0x3, 0x2, 0x2, 0x2, 0x225, 0x227, 0x3, 0x2, 0x2, 0x2, 
    0x226, 0x224, 0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 0x7, 0x6, 0x2, 0x2, 
    0x228, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x229, 0x21d, 0x3, 0x2, 0x2, 0x2, 
    0x22a, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x229, 0x3, 0x2, 0x2, 0x2, 
    0x22b, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22f, 0x3, 0x2, 0x2, 0x2, 
    0x22d, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x1e9, 0x3, 0x2, 0x2, 0x2, 
    0x22e, 0x212, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x230, 
    0x23c, 0x5, 0x40, 0x21, 0x2, 0x231, 0x232, 0x7, 0x5, 0x2, 0x2, 0x232, 
    0x237, 0x5, 0x46, 0x24, 0x2, 0x233, 0x234, 0x7, 0x7, 0x2, 0x2, 0x234, 
    0x236, 0x5, 0x46, 0x24, 0x2, 0x235, 0x233, 0x3, 0x2, 0x2, 0x2, 0x236, 
    0x239, 0x3, 0x2, 0x2, 0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 0x2, 0x237, 
    0x238, 0x3, 0x2, 0x2, 0x2, 0x238, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x239, 
    0x237, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x7, 0x6, 0x2, 0x2, 0x23b, 
    0x23d, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x231, 0x3, 0x2, 0x2, 0x2, 0x23c, 
    0x23d, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x240, 
    0x9, 0x5, 0x2, 0x2, 0x23f, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 
    0x3, 0x2, 0x2, 0x2, 0x240, 0x241, 0x3, 0x2, 0x2, 0x2, 0x241, 0x242, 
    0x7, 0x9a, 0x2, 0x2, 0x242, 0x31, 0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 
    0x9, 0x6, 0x2, 0x2, 0x244, 0x33, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 0x7, 
    0x9c, 0x2, 0x2, 0x246, 0x35, 0x3, 0x2, 0x2, 0x2, 0x247, 0x24a, 0x5, 
    0x1c, 0xf, 0x2, 0x248, 0x24a, 0x5, 0x18, 0xd, 0x2, 0x249, 0x247, 0x3, 
    0x2, 0x2, 0x2, 0x249, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x24b, 0x24c, 0x9, 0x7, 0x2, 0x2, 0x24c, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x24d, 0x24e, 0x9, 0x8, 0x2, 0x2, 0x24e, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x24f, 0x250, 0x5, 0x5c, 0x2f, 0x2, 0x250, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x251, 0x252, 0x5, 0x5c, 0x2f, 0x2, 0x252, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x253, 0x254, 0x5, 0x5c, 0x2f, 0x2, 0x254, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x255, 0x256, 0x5, 0x5c, 0x2f, 0x2, 0x256, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x257, 0x258, 0x5, 0x5c, 0x2f, 0x2, 0x258, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x259, 0x25a, 0x5, 0x5c, 0x2f, 0x2, 0x25a, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x25b, 0x25c, 0x5, 0x5c, 0x2f, 0x2, 0x25c, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x25d, 0x25e, 0x5, 0x5c, 0x2f, 0x2, 0x25e, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x25f, 0x260, 0x5, 0x5c, 0x2f, 0x2, 0x260, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x261, 0x262, 0x5, 0x5c, 0x2f, 0x2, 0x262, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x263, 0x264, 0x5, 0x5c, 0x2f, 0x2, 0x264, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x265, 0x266, 0x5, 0x5c, 0x2f, 0x2, 0x266, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x267, 0x268, 0x5, 0x5c, 0x2f, 0x2, 0x268, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x269, 0x26a, 0x5, 0x5c, 0x2f, 0x2, 0x26a, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x26b, 0x26c, 0x5, 0x5c, 0x2f, 0x2, 0x26c, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x26d, 0x26e, 0x5, 0x5c, 0x2f, 0x2, 0x26e, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x26f, 0x277, 0x7, 0x99, 0x2, 0x2, 0x270, 0x277, 0x5, 0x3a, 0x1e, 0x2, 
    0x271, 0x277, 0x7, 0x9c, 0x2, 0x2, 0x272, 0x273, 0x7, 0x5, 0x2, 0x2, 
    0x273, 0x274, 0x5, 0x5c, 0x2f, 0x2, 0x274, 0x275, 0x7, 0x6, 0x2, 0x2, 
    0x275, 0x277, 0x3, 0x2, 0x2, 0x2, 0x276, 0x26f, 0x3, 0x2, 0x2, 0x2, 
    0x276, 0x270, 0x3, 0x2, 0x2, 0x2, 0x276, 0x271, 0x3, 0x2, 0x2, 0x2, 
    0x276, 0x272, 0x3, 0x2, 0x2, 0x2, 0x277, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x60, 0x62, 0x6d, 0x74, 0x79, 0x7f, 0x89, 0x8d, 0x99, 0xa7, 0xb1, 0xba, 
    0xbd, 0xcb, 0xd7, 0xe2, 0xe9, 0xee, 0xf5, 0xfe, 0x103, 0x10c, 0x111, 
    0x113, 0x11c, 0x11f, 0x125, 0x127, 0x136, 0x13b, 0x144, 0x147, 0x155, 
    0x161, 0x168, 0x16e, 0x175, 0x179, 0x181, 0x193, 0x19f, 0x1a7, 0x1a9, 
    0x1ab, 0x1b0, 0x1b6, 0x1bb, 0x1c4, 0x1c9, 0x1db, 0x1de, 0x1e0, 0x1e4, 
    0x1e7, 0x1eb, 0x1f2, 0x1fb, 0x200, 0x209, 0x20e, 0x210, 0x219, 0x224, 
    0x22b, 0x22e, 0x237, 0x23c, 0x23f, 0x249, 0x276, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

chainsqlParser::Initializer chainsqlParser::_init;
