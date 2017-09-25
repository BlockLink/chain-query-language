#pragma once

#include <chainsql/chainsql_types.h>
#include <string>

namespace chainsql
{
	class ChainsqlBaseVisitor
	{
	public:
		virtual ~ChainsqlBaseVisitor() {}

		virtual std::string visitShowTablesStmt(ChainsqlShowTablesStmt *stmt) { return ""; };
		virtual std::string visitCreateTableStmt(ChainsqlCreateTableStmt *stmt) { return ""; };
		virtual std::string visitCreateIndexStmt(ChainsqlCreateIndexStmt *stmt) { return ""; };
		virtual std::string visitInsertStmt(ChainsqlInsertStmt *stmt) { return ""; };
		virtual std::string visitUpdateStmt(ChainsqlUpdateStmt *stmt) { return ""; };
		virtual std::string visitDeleteStmt(ChainsqlDeleteStmt *stmt) { return ""; };
		virtual std::string visitSelectStmt(ChainsqlSelectStmt *stmt) { return ""; };
	};
}
