// chainsql的各种语法分析结构

#pragma once

#include <string>
#include <vector>
#include <memory>

namespace chainsql
{
	struct ChainsqlColumnDef
	{
		std::string column_name;
		std::string column_type;
	};

	enum ChainsqlStmtType
	{
		CST_CREATE_TABLE = 0,
		CST_CREATE_INDEX = 1,
		CST_SELECT = 2,
		CST_INSERT = 3,
		CST_UPDATE = 4,
		CST_DELETE = 5,
		CST_SHOW_TABLES = 6
	};

	class ChainsqlBaseVisitor;

	class ChainsqlStmt
	{
	private:

	public:
		virtual ~ChainsqlStmt();

		virtual ChainsqlStmtType stmt_type() const = 0;

		virtual std::string accept(ChainsqlBaseVisitor *visitor) = 0;
	};

	class ChainsqlCreateTableStmt : public ChainsqlStmt
	{
	private:
		std::string _table_name;
		std::vector<ChainsqlColumnDef> _column_defs;
	public:
		inline virtual ChainsqlStmtType stmt_type() const 
		{
			return ChainsqlStmtType::CST_CREATE_TABLE;
		}
		inline virtual ~ChainsqlCreateTableStmt() {}
		inline std::string table_name() const { return _table_name; }
		void set_table_name(std::string table_name);
		inline std::vector<ChainsqlColumnDef> column_defs() const { return _column_defs; }
		void add_column_def(ChainsqlColumnDef column_def);
		void add_column_defs(std::vector<ChainsqlColumnDef> &column_defs);
		virtual std::string accept(ChainsqlBaseVisitor *visitor);
	};

	struct ChainsqlCreateIndexStmt : public ChainsqlStmt
	{
	public:
		std::string index_name;
		bool unique;
		std::string table_name;
		std::vector<std::pair<std::string, bool>> column_names; // column_name=>isAscending
	public:
		inline ChainsqlCreateIndexStmt() : unique(false) {}
		inline virtual ~ChainsqlCreateIndexStmt() {}
		inline virtual ChainsqlStmtType stmt_type() const
		{
			return ChainsqlStmtType::CST_CREATE_INDEX;
		}
		virtual std::string accept(ChainsqlBaseVisitor *visitor);
	};

	struct ChainsqlResultColumn
	{
		std::vector<std::string> tokens;
	};

	struct ChainsqlTableQuery
	{
		std::string table_name;
		std::string alias;
	};

	struct ChainsqlExpr
	{
		std::vector<std::string> tokens;
		inline ChainsqlExpr(std::vector<std::string> tokens_ = {})
		{
			this->tokens = tokens_;
		}
	};

	struct ChainsqlGroupBy
	{
		std::vector<ChainsqlExpr> exprs; // group by后可以跟一个或多个表达式
		std::shared_ptr<ChainsqlExpr> having_expr; // group by 后可选跟一个having表达式
	};

	struct ChainsqlOrderInfo
	{
		std::string column_name;
		bool ascending;
		inline ChainsqlOrderInfo(std::string column_name_, bool ascending_)
		{
			this->column_name = column_name_;
			this->ascending = ascending_;
		}
	};

	struct ChainsqlSelectStmt : public ChainsqlStmt
	{
	public:
		std::vector<ChainsqlResultColumn> result_columns;
		std::vector<ChainsqlTableQuery> tables;
		size_t limit;
		size_t offset;
		bool distinct;
		bool all;
		std::shared_ptr<ChainsqlExpr> condition; // where 后面跟着的表达式
		std::vector<ChainsqlOrderInfo> orders; // order by后面跟着的排序， column_name => isAscending
		std::shared_ptr<ChainsqlGroupBy> group_by;
	public:
		ChainsqlSelectStmt();
		inline virtual ChainsqlStmtType stmt_type() const
		{
			return ChainsqlStmtType::CST_SELECT;
		}
		virtual std::string accept(ChainsqlBaseVisitor *visitor);
	};

	class ChainsqlInsertStmt : public ChainsqlStmt
	{
	private:
		std::string _table_name;
		std::vector<std::string> _column_names;
		std::vector<ChainsqlExpr> _column_values; // insert语句的每个值可能由多个token组成
	public:
		inline virtual ChainsqlStmtType stmt_type() const
		{
			return ChainsqlStmtType::CST_INSERT;
		}
		void set_table_name(std::string table_name);
		inline std::string table_name() const { return _table_name; }
		inline std::vector<std::string> column_names() const { return _column_names; }
		inline std::vector<ChainsqlExpr> column_values() const { return _column_values; }
		void add_column_name(std::string column_name);
		void add_column_value(ChainsqlExpr value_tokens);
		virtual std::string accept(ChainsqlBaseVisitor *visitor);
	};

	struct ChainsqlUpdateStmt : public ChainsqlStmt
	{
	public:
		std::string table_name;
		std::vector<std::pair<std::string, ChainsqlExpr>> set_columns; // 要修改的列, 每一项是 column_name => value expr
		std::shared_ptr<ChainsqlExpr> condition; // where 后面跟着的表达式, TODO: 改成更加结构化的数据类型
		std::vector<ChainsqlOrderInfo> orders; // order by后面跟着的排序
		size_t limit; // limit 后面跟着的数字
	public:
		inline ChainsqlUpdateStmt() { limit = 0; }
		inline virtual ChainsqlStmtType stmt_type() const
		{
			return ChainsqlStmtType::CST_UPDATE;
		}
		virtual std::string accept(ChainsqlBaseVisitor *visitor);
	};

	struct ChainsqlDeleteStmt : public ChainsqlStmt
	{
	public:
		std::string table_name;
		std::shared_ptr<ChainsqlExpr> condition; // where 后面跟着的表达式, TODO: 改成更加结构化的数据类型
		std::vector<ChainsqlOrderInfo> orders; // order by后面跟着的排序
		size_t limit; // limit 后面跟着的数字

	public:
		inline ChainsqlDeleteStmt() { limit = 0; }
		inline virtual ChainsqlStmtType stmt_type() const
		{
			return ChainsqlStmtType::CST_DELETE;
		}
		virtual std::string accept(ChainsqlBaseVisitor *visitor);
	};

	class ChainsqlShowTablesStmt : public ChainsqlStmt
	{
	public:
		inline virtual ChainsqlStmtType stmt_type() const
		{
			return ChainsqlStmtType::CST_SHOW_TABLES;
		}
		virtual std::string accept(ChainsqlBaseVisitor *visitor);
	};

}
