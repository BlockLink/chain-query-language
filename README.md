chain-query-language
===========

SQL-like language（chainsql) for blockchain to read/write storage

# Features
* 类SQL的语法
* 不同区块链合约的chainsql执行可以相对独立不影响
* 区块链回滚时可以反向执行chainsql把合约状态数据(storage数据)回滚
* chainsql执行的数据变化量可控


# Dependencies

* C++ 11
* antlr4 (or unzip lib/antlr4/antlr4.7z when build in Windows)

# Grammar

```

    column types: int, bigint, bool, varchar(n), text, string

	allowed functions: avg, count, sum, min, max, trim, upper, lower, abs, substr, length

	disabled column names: _id

    create table userBalances (freeze bool, userId varchar(255), balance bigint, id bigint); // 创建表结构语句不能重复创建同名表，否则会报错。实际创建时会自动创建一个 _id 列，创建表时不能手动提供 _id 列
	create index userBalanceIdKey on userBalances (id); // 创建索引语句，不能重复创建同名索引
	create unique userBalanceIdKey on userBalances (id); // 创建唯一索引语句，不能重复创建同名索引
	insert into userBalances (freeze, userId, balance, id) values (false, 'abcd', 12345, 1); // 插入记录到表中. 插入的列不能手动提供 _id 列，区块链执行时diff记录新记录的 _id列的值 
	select userBalance.userAddress from userBalances as userBalance where freeze=true order by id desc limit 100 offset 10; // select语句中limit是必须的，且有上限
	update userBalances set balance=12345 where freeze=false limit 100; // update语句中limit是必须的，且有上限. 区块链执行时diff中要记录下来update之前这些被修改记录的数据和_id，保存的还是diff
	delete from userBalances where freeze=true limit 100; // delete语句中limit是必须的，且有上限. 区块链执行时diff中要记录下来delete之前这些被修改记录的数据和_id，保存的还是diff
	show tables; // 查询所有表的名称的命令
```

# BlockChain rollback strategy

* 区块链执行合约中chainsql时，op存储每条chainsql和每条chainsql携带的diff数据，diff数据包含可以用来完全回滚的关键数据
* 区块链回滚时，反转执行合约中执行的chainsql
* create table语句的回滚: 删除此数据表
* create index/create unique的回滚
* insert语句回滚时，op中记录了这条chainsql产生的新记录的_id列的值，用来删除数据
* select语句和show tables语句不需要回滚
* update语句回滚时，op中记录了被影响的记录的_id列的值，以及执行前的这些记录的数据，可以用来回滚记录
* delete语句回滚时，op中记录了被删除的记录的_id列的值和执行前这些记录的数据，可以用来回滚记录

# Usage

```
	// chainsql例子
	create table userBalances (freeze bool, userId varchar(255), balance bigint, id bigint); 
	create index userBalanceIdKey on userBalances (id desc);
	create unique index userBalanceIdKey on userBalances (id);
	insert into userBalances (freeze, userId, balance, id) values (false, 'abcd', 12345, 1);
	select userBalance.userAddress from userBalances userBalance where freeze=true group by age having count(1)>10 order by id desc limit 100;
	update userBalances set balance=12345 where freeze=false limit 100; 
	update userBalances set balance=12345 where freeze=false order by id desc limit 100;
	delete from userBalances where freeze=true limit 100; 
	delete from userBalances limit 100;
	delete from userBalances where freeze=true order by id asc limit 100;
	show tables;

	// C++使用chainsql的例子

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

	ChainsqlLangParser lang_parser;
	auto tr = lang_parser.parse(stream);
	lang_parser.walk(tr);
	auto stmts = lang_parser.chainsql_stmts();

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

```