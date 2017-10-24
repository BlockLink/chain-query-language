#pragma once
#include <string>
#include <vector>
#include <chainsql/chainsql_types.h>

namespace chainsql
{
	//chainsql执行后产生的change_info，为了支持回滚，转换成反向的chainsqls
	class RollbackTranslator
	{
	public:
		std::string _sql_table_prefix; // 要给sql表增加的前缀
	public:
		RollbackTranslator(std::string sql_table_prefix);
		virtual ~RollbackTranslator();

		std::vector<std::string> generate_rollback_sqls(const SqlChangeInfo &change_info);

	private:
		// 把chainsql中的table name转成目标sql的table name
		std::string wrap_table_name(std::string chainsql_table_name);
	};
}
