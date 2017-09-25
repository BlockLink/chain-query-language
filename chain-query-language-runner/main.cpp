#include <iostream>

#include <stdint.h>
#include <sstream>
#include <antlr4-runtime.h>
#include <chainsql/chainsql_visitor.h>
#include <chainsql/chainsql_lang_parser.h>
#include <chainsql/chainsql_to_sql_translator.h>
#include <chainsql/exceptions.h>

#pragma execution_character_set("utf-8")

using namespace antlr4;
using namespace antlr4::tree;
using namespace chainsql;

static void printTree(std::stringstream &ss, tree::ParseTree *tr, size_t indents_count = 0)
{
	std::stringstream indents_ss;
	for (size_t i = 0; i < indents_count; i++)
		indents_ss << "\t";
	const auto &indents = indents_ss.str();
	auto children = tr->children;

	if (children.empty())
	{
		ss << indents << tr->getText();
		ss << std::endl;
	}
	for (auto item : children)
	{
		printTree(ss, item, indents_count + 1);
	}
}

class DemoChainsqlVisitor : public ChainsqlBaseVisitor
{
public:
	inline virtual ~DemoChainsqlVisitor() {}
	virtual std::string visitShowTablesStmt(ChainsqlShowTablesStmt *stmt)
	{
		return "visit show tables stmt";
	};
	virtual std::string visitCreateTableStmt(ChainsqlCreateTableStmt *stmt)
	{
		return "visit create table stmt";
	};
	virtual std::string visitCreateIndexStmt(ChainsqlCreateIndexStmt *stmt)
	{
		return "visit create index stmt";
	};
	virtual std::string visitInsertStmt(ChainsqlInsertStmt *stmt)
	{
		return "visit insert stmt";
	};
	virtual std::string visitUpdateStmt(ChainsqlUpdateStmt *stmt)
	{
		return "visit update stmt";
	};
	virtual std::string visitDeleteStmt(ChainsqlDeleteStmt *stmt)
	{
		return "visit delete stmt";
	};
	virtual std::string visitSelectStmt(ChainsqlSelectStmt *stmt)
	{
		return "visit select stmt";
	};
};

int main(int argc, const char* argv[]) {
	std::ifstream stream;
	stream.open(argv[1]);

	try
	{
		ChainsqlLangParser lang_parser;
		auto tr = lang_parser.parse(stream);
		lang_parser.walk(tr);

		std::stringstream ss;
		printTree(ss, tr);
		auto tree_str = ss.str();

		std::cout << "tree structure is: " << std::endl;
		std::cout << tree_str << std::endl;

		auto stmts = lang_parser.chainsql_stmts();

		std::cout << "found " << stmts.size() << " chainsql statements" << std::endl;

		DemoChainsqlVisitor visitor;
		ChainsqlToSqlTranslater to_sql_translator("demo1_");

		for (const auto &stmt : stmts)
		{
			auto stmt_response = stmt->accept(&visitor);
			std::cout << stmt_response << std::endl;

			auto sql = stmt->accept(&to_sql_translator);
			std::cout << "to sql is: " << sql << std::endl;
		}
		// 如果区块链要执行回滚操作，提供2个visitor类，一个正常执行chainsql，一个回滚执行chainsql
	}
	catch (ChainsqlException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}