#pragma once

#include <sstream>
#include <antlr4/antlr4-runtime.h>
#include <memory>
#include <chainsql/chainsqlLexer.h>
#include <chainsql/chainsqlParser.h>
#include <chainsql/chainsqlBaseListener.h>
#include <chainsql/chainsql_structure_listener.h>
#include <chainsql/chainsql_meta_executor.h>
#include <chainsql/chainsql_rollback_translator.h>
#include <chainsql/exceptions.h>

namespace chainsql
{
	using namespace antlr4;
	using namespace antlr4::tree;

	class ChainsqlLangParser
	{
	private:
		std::shared_ptr<chainsqlStructureListener> _chainsql_structure_listener;
		std::shared_ptr<chainsqlParser> _parser;
		std::shared_ptr<CommonTokenStream> _tokens;
		std::shared_ptr<chainsqlLexer> _lexer;
		std::shared_ptr<ANTLRInputStream> _antlr_input_stream;
	private:
		tree::ParseTree *parse(ANTLRInputStream *input);
	public:
		ChainsqlLangParser();
		virtual ~ChainsqlLangParser();

		tree::ParseTree *parse_string(std::string input);
		tree::ParseTree *parse(std::istream &stream);

		void walk(tree::ParseTree *tree);

		std::vector<ChainsqlStmt*> chainsql_stmts() const;
	};
}
