#pragma once
#include <string>
#include <vector>
#include <chainsql/chainsql_types.h>

namespace chainsql
{
	//chainsqlִ�к������change_info��Ϊ��֧�ֻع���ת���ɷ����chainsqls
	class RollbackTranslator
	{
	public:
		std::string _sql_table_prefix; // Ҫ��sql�����ӵ�ǰ׺
	public:
		RollbackTranslator(std::string sql_table_prefix);
		virtual ~RollbackTranslator();

		std::vector<std::string> generate_rollback_sqls(const SqlChangeInfo &change_info);

	private:
		// ��chainsql�е�table nameת��Ŀ��sql��table name
		std::string wrap_table_name(std::string chainsql_table_name);
	};
}
