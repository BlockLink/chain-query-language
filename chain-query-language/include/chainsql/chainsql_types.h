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

		template <typename T>
		T* as()
		{
			return (T*)this;
		}
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

	// data types
	enum SqlColumnTypeEnum
	{
		SCT_INT = 0,
		SCT_BIGINT = 1,
		SCT_BOOL = 2,
		SCT_NVARCHAR = 3,
		SCT_TEXT = 4,
		SCT_STRING = 5
	};

	struct SqlValue
	{
		int64_t int_value;
		bool bool_value;
		std::string string_value;
		SqlColumnTypeEnum type;
		bool is_null;
		inline SqlValue(SqlColumnTypeEnum _type= SqlColumnTypeEnum::SCT_INT)
			: is_null(false), type(_type)
		{}
	public:
		static SqlValue create_null();
		static SqlValue create_int(int64_t value);
		static SqlValue create_bigint(int64_t value);
		static SqlValue create_string(const std::string &value);
		static SqlValue create_varchar(const std::string &value);
		static SqlValue create_text(const std::string &value);
		static SqlValue create_bool(bool value);
	};

	typedef uint64_t row_id_type;

	struct SqlResultRow
	{
		std::vector<SqlValue> column_values;
	};
	struct SqlResultSet
	{
		std::vector<std::string> column_names;
		std::vector<SqlResultRow> rows;
	};

	struct SqlTableColumns
	{
		std::vector<std::string> column_names;

	public:
		inline SqlTableColumns(const std::vector<std::string> &_column_names)
			: column_names(_column_names)
		{
		}
		inline SqlTableColumns()
		{}
	};

	struct SqlRecordData
	{
		std::vector<SqlValue> column_values;
	};

	// change info when sql execute
	struct SqlChangeInfo
	{
		std::string execute_chainsql; // 执行的chainsql
		ChainsqlStmtType stmt_type; // chainsql的语句类型
		std::string table_name; // 影响的表名(非实际)
		std::string index_name; // 影响的索引名(非实际)
		row_id_type inserted_id; // 新增的id
		SqlTableColumns columns;
		std::vector<std::pair<row_id_type, SqlRecordData>> updated_before_records; // update被修改的记录的 _id 和旧数据记录
		std::vector<std::pair<row_id_type, SqlRecordData>> deleted_before_records; // delete被删除的记录的 _id 和旧数据记录

		SqlChangeInfo();

		// 检查SqlChangeInfo内容是否完整，格式准确
		bool validate() const;
	};

	// TODO: 根据SqlChangeInfo产生回滚需要执行的chainsql列表

}
