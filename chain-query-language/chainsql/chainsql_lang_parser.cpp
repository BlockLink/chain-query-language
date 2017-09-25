#include <chainsql/chainsql_lang_parser.h>
#include <chainsql/exceptions.h>

namespace chainsql
{
	ChainsqlLangParser::ChainsqlLangParser()
	{
		_chainsql_structure_listener = std::make_shared<chainsqlStructureListener>();
	}

	ChainsqlLangParser::~ChainsqlLangParser()
	{

	}

	tree::ParseTree* ChainsqlLangParser::parse(ANTLRInputStream *input)
	{
		_lexer = std::make_shared<chainsqlLexer>(_antlr_input_stream.get());
		_tokens = std::make_shared<CommonTokenStream>(_lexer.get());
		_parser = std::make_shared<chainsqlParser>(_tokens.get());
		// std::string s = tr->toStringTree(&parser);
		// std::cout << s << std::endl;
		try
		{
			return _parser->parse();
		}
		catch (RuntimeException *e)
		{
			std::string msg(e->what());
			delete e;
			throw chainsql::ChainsqlException(msg);
		}
	}

	tree::ParseTree* ChainsqlLangParser::parse(std::istream &stream)
	{
		_antlr_input_stream = std::make_shared<ANTLRInputStream>(stream);
		return parse(_antlr_input_stream.get());
	}

	tree::ParseTree* ChainsqlLangParser::parse(std::string input)
	{
		_antlr_input_stream = std::make_shared<ANTLRInputStream>(input);
		return parse(_antlr_input_stream.get());
	}

	void ChainsqlLangParser::walk(tree::ParseTree *tree)
	{
		try
		{
			tree::ParseTreeWalker::DEFAULT.walk(_chainsql_structure_listener.get(), tree);
		}
		catch (RuntimeException &e)
		{
			throw chainsql::ChainsqlException(e.what());
		}
	}

	std::vector<ChainsqlStmt*> ChainsqlLangParser::chainsql_stmts() const
	{
		return _chainsql_structure_listener->chainsql_stmts();
	}

}
