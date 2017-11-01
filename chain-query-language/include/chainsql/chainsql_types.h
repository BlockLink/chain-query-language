// chainsql�ĸ����﷨�����ṹ

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <fc/io/enum_type.hpp>

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
		std::vector<ChainsqlExpr> exprs; // group by����Ը�һ���������ʽ
		std::shared_ptr<ChainsqlExpr> having_expr; // group by ���ѡ��һ��having���ʽ
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
		std::shared_ptr<ChainsqlExpr> condition; // where ������ŵı��ʽ
		std::vector<ChainsqlOrderInfo> orders; // order by������ŵ����� column_name => isAscending
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
		std::vector<ChainsqlExpr> _column_values; // insert����ÿ��ֵ�����ɶ��token���
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
		std::vector<std::pair<std::string, ChainsqlExpr>> set_columns; // Ҫ�޸ĵ���, ÿһ���� column_name => value expr
		std::shared_ptr<ChainsqlExpr> condition; // where ������ŵı��ʽ, TODO: �ĳɸ��ӽṹ������������
		std::vector<ChainsqlOrderInfo> orders; // order by������ŵ�����
		size_t limit; // limit ������ŵ�����
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
		std::shared_ptr<ChainsqlExpr> condition; // where ������ŵı��ʽ, TODO: �ĳɸ��ӽṹ������������
		std::vector<ChainsqlOrderInfo> orders; // order by������ŵ�����
		size_t limit; // limit ������ŵ�����

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
		fc::enum_type<uint8_t, SqlColumnTypeEnum> type;
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
		std::string execute_chainsql; // ִ�е�chainsql
		fc::enum_type<uint8_t, ChainsqlStmtType> stmt_type; // chainsql���������
		std::string table_name; // Ӱ��ı���(��ʵ��)
		std::string index_name; // Ӱ���������(��ʵ��)
		row_id_type inserted_id; // ������id
		SqlTableColumns columns;
		std::vector<std::pair<row_id_type, SqlRecordData>> updated_before_records; // update���޸ĵļ�¼�� _id �;����ݼ�¼
		std::vector<std::pair<row_id_type, SqlRecordData>> deleted_before_records; // delete��ɾ���ļ�¼�� _id �;����ݼ�¼

		SqlChangeInfo();

		// ���SqlChangeInfo�����Ƿ���������ʽ׼ȷ
		bool validate() const;
	};

}
