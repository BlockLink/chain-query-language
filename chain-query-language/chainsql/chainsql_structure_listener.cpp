#include <chainsql/chainsql_structure_listener.h>
#include <iostream>
#include <chainsql/exceptions.h>
#include <chainsql/utils.h>

namespace chainsql
{
	// chainsql中expr表达式允许使用的函数名称列表
	static std::vector<std::string> chainsql_allowed_expr_functions = {
		"avg", "count", "sum", "min", "max", "trim", "upper", "lower", "abs", "substr", "length"
	};

	// chainsql中字段类型允许使用的类型名称白名单
	static std::vector<std::string> chainsql_allowed_column_types = {
		"int", "bigint", "varchar", "text", "bool", "string"
	};

	// chainsql中禁止使用的字段名称列表
	static std::vector<std::string> chainsql_disabled_column_names = {
		"_id"
	};

	chainsqlStructureListener::~chainsqlStructureListener()
	{

	}

	std::vector<ChainsqlStmt*> chainsqlStructureListener::chainsql_stmts() const
	{
		return _chainsql_stmts;
	}

	void chainsqlStructureListener::enterParse(chainsqlParser::ParseContext * ctx)
	{
		_chainsql_stmts.clear();
	}
	void chainsqlStructureListener::exitParse(chainsqlParser::ParseContext * ctx)
	{
		std::cout << "exitParse" << std::endl;
	}
	void chainsqlStructureListener::enterError(chainsqlParser::ErrorContext * ctx)
	{
		std::cout << "enterError" << std::endl;
	}
	void chainsqlStructureListener::exitError(chainsqlParser::ErrorContext * ctx)
	{
		std::cout << "exitError" << std::endl;
	}
	void chainsqlStructureListener::enterSql_stmt_list(chainsqlParser::Sql_stmt_listContext * ctx)
	{
		std::cout << "enterSql_stmt_list" << std::endl;
	}
	void chainsqlStructureListener::exitSql_stmt_list(chainsqlParser::Sql_stmt_listContext * ctx)
	{
		std::cout << "exitSql_stmt_list" << std::endl;
	}
	void chainsqlStructureListener::enterSql_stmt(chainsqlParser::Sql_stmtContext * ctx)
	{
		std::cout << "enterSql_stmt" << std::endl;
	}
	void chainsqlStructureListener::exitSql_stmt(chainsqlParser::Sql_stmtContext * ctx)
	{
		std::cout << "exitSql_stmt" << std::endl;
	}
	void chainsqlStructureListener::enterCreate_table_stmt(chainsqlParser::Create_table_stmtContext * ctx)
	{
		_tmp_column_defs.clear();
	}
	void chainsqlStructureListener::exitCreate_table_stmt(chainsqlParser::Create_table_stmtContext * ctx)
	{
		ChainsqlCreateTableStmt *stmt_p = nullptr;
		{
			auto stmt = std::make_unique<ChainsqlCreateTableStmt>();
			stmt_p = stmt.get();
			_chainsql_ctx.add_managed_create_table_stmt(std::move(stmt));
		}
		_chainsql_stmts.push_back(stmt_p);
		const auto &children = ctx->children;
		if (children.size() < 4)
		{
			throw ChainsqlException("create table stmt syntax error");
		}
		auto table_name = children[2]->getText();
		stmt_p->set_table_name(table_name);
		stmt_p->add_column_defs(_tmp_column_defs);
		_tmp_column_defs.clear();
	}

	void chainsqlStructureListener::enterCreate_index_stmt(chainsqlParser::Create_index_stmtContext * ctx)
	{
		
	}
	void chainsqlStructureListener::exitCreate_index_stmt(chainsqlParser::Create_index_stmtContext * ctx)
	{
		ChainsqlCreateIndexStmt *stmt_p = nullptr;
		{
			auto stmt = std::make_unique<ChainsqlCreateIndexStmt>();
			stmt_p = stmt.get();
			_chainsql_ctx.add_managed_create_index_stmt(std::move(stmt));
		}
		_chainsql_stmts.push_back(stmt_p);

		const auto &children = ctx->children;
		if (children.size() < 8)
		{
			throw ChainsqlException("create index stmt syntax error");
		}

		auto index_keyword = children[1]->getText();
		stmt_p->unique = utils::string_to_lower(index_keyword) == "unique";
		size_t iter_index = 2;
		if (stmt_p->unique)
			iter_index++;
		// now iter_index points to index_name
		auto index_name = children[iter_index]->getText();
		stmt_p->index_name = index_name;
		iter_index = iter_index + 2;
		auto table_name = children[iter_index]->getText();
		stmt_p->table_name = table_name;
		iter_index = iter_index + 2;
		// now iter_index points to first indexed_column
		while (iter_index < children.size())
		{
			auto index_column_tree = children[iter_index];
			auto index_column_tokens = utils::tokens_from_parse_tree(index_column_tree);
			auto index_column_name = index_column_tokens[0];
			auto ascending = true;
			if (index_column_tokens.size() >= 2)
			{
				auto order = utils::string_to_lower(index_column_tokens[1]);
				if (order == "desc")
					ascending = false;
				else if (order == "asc")
					ascending = true;
				else
					throw ChainsqlException(std::string("create index stmt syntax error, not support index order ") + order);
			}
			stmt_p->column_names.push_back(std::make_pair(index_column_name, ascending));
			if (iter_index >= children.size() - 1 || children[iter_index + 1]->getText() == ")")
				break;
			iter_index = iter_index + 2;
		}
	}

	void chainsqlStructureListener::enterDelete_stmt_limited(chainsqlParser::Delete_stmt_limitedContext * /*ctx*/)
	{
		
	}
	void chainsqlStructureListener::exitDelete_stmt_limited(chainsqlParser::Delete_stmt_limitedContext * ctx)
	{
		ChainsqlDeleteStmt *stmt_p = nullptr;
		{
			auto stmt = std::make_unique<ChainsqlDeleteStmt>();
			stmt_p = stmt.get();
			_chainsql_ctx.add_managed_delete_stmt(std::move(stmt));
		}
		_chainsql_stmts.push_back(stmt_p);

		const auto &children = ctx->children;
		if (children.size() < 5)
		{
			throw ChainsqlException("delete stmt syntax error");
		}
		size_t iter_index = 2;
		// now iter_index points to table_name
		auto table_name = children[iter_index]->getText();
		stmt_p->table_name = table_name;
		iter_index++;
		if (iter_index < children.size() && utils::string_to_lower(children[iter_index]->getText()) == "where")
		{
			// iter_index points to where keyword
			iter_index++;
			auto condition_tree = children[iter_index];
			auto condition_tokens = utils::tokens_from_parse_tree(condition_tree);
			stmt_p->condition = std::make_shared<ChainsqlExpr>(condition_tokens);
			iter_index++;
		}
		if (iter_index < children.size()-1 && utils::string_to_lower(children[iter_index]->getText()) == "order" && utils::string_to_lower(children[iter_index + 1]->getText()) == "by")
		{
			// iter_index points to order keyword
			iter_index += 2;
			// iter_index points to first ordering_term
			while (iter_index < children.size())
			{
				auto ordering_term_tree = children[iter_index];
				auto ordering_term_tokens = utils::tokens_from_parse_tree(ordering_term_tree);
				auto order_column_name = ordering_term_tokens[0];
				auto ascending = true;
				if (ordering_term_tokens.size() >= 2)
				{
					auto order = utils::string_to_lower(ordering_term_tokens[1]);
					if (order == "desc")
						ascending = false;
					else if (order == "asc")
						ascending = true;
					else
						throw ChainsqlException(std::string("delete stmt syntax error, not support index order ") + order);
				}
				stmt_p->orders.push_back(ChainsqlOrderInfo(order_column_name, ascending));
				if (iter_index >= children.size() - 1 || utils::string_to_lower(children[iter_index + 1]->getText()) == "limit")
					break;
				iter_index += 2;
			}
			iter_index += 1;
		}
		iter_index++;
		if (iter_index >= children.size())
			throw ChainsqlException("delete stmt syntax error");
		auto limit_exp = children[iter_index]->getText();
		if (!utils::string_is_digits(limit_exp))
		{
			throw ChainsqlException(std::string("delete stmt syntax error, not support limit value ") + limit_exp);
		}
		auto limit = std::stol(limit_exp);
		if (limit < 0)
		{
			throw ChainsqlException(std::string("delete stmt syntax error, not support limit value ") + limit_exp);
		}
		stmt_p->limit = limit;
	}

	void chainsqlStructureListener::enterInsert_stmt(chainsqlParser::Insert_stmtContext * /*ctx*/)
	{
		_tmp_column_defs.clear();
	}
	void chainsqlStructureListener::exitInsert_stmt(chainsqlParser::Insert_stmtContext * ctx)
	{
		ChainsqlInsertStmt *stmt_p = nullptr;
		{
			auto stmt = std::make_unique<ChainsqlInsertStmt>();
			stmt_p = stmt.get();
			_chainsql_ctx.add_managed_insert_stmt(std::move(stmt));
		}
		_chainsql_stmts.push_back(stmt_p);
		const auto &children = ctx->children;
		if (children.size() < 10)
		{
			throw ChainsqlException("insert table stmt syntax error");
		}
		auto table_name = children[2]->getText();
		stmt_p->set_table_name(table_name);
		size_t iter_index = 0;
		for (iter_index = 4; iter_index < children.size();)
		{
			auto column_name = children[iter_index]->getText();
			if (!column_name.empty())
				stmt_p->add_column_name(column_name);
			if (iter_index >= children.size() - 1 || children[iter_index + 1]->getText() == ")")
			{
				iter_index++; // now iter_index points to ')'
				break;
			}
			iter_index += 2;
		}
		iter_index ++;
		if (iter_index >= children.size())
		{
			throw ChainsqlException("insert table stmt syntax error");
		}
		auto values_keyword = children[iter_index]->getText();
		for (iter_index=iter_index+2; iter_index < children.size();)
		{
			auto tokens = utils::tokens_from_parse_tree(children[iter_index]);
			if (!tokens.empty())
				stmt_p->add_column_value(ChainsqlExpr(tokens));
			if (iter_index >= children.size() - 1 || children[iter_index + 1]->getText() == ")")
			{
				break;
			}
			iter_index += 2;
		}
	}

	void chainsqlStructureListener::enterSelect_stmt(chainsqlParser::Select_stmtContext * /*ctx*/)
	{
		
	}
	void chainsqlStructureListener::exitSelect_stmt(chainsqlParser::Select_stmtContext * ctx)
	{
		ChainsqlSelectStmt *stmt_p = nullptr;
		{
			auto stmt = std::make_unique<ChainsqlSelectStmt>();
			stmt_p = stmt.get();
			_chainsql_ctx.add_managed_select_stmt(std::move(stmt));
		}
		_chainsql_stmts.push_back(stmt_p);

		const auto &children = ctx->children;
		if (children.size() < 4)
		{
			throw ChainsqlException("insert table stmt syntax error");
		}
		size_t iter_index = 1;
		// iter_index points to distinct/all or first result_column
		if (utils::string_to_lower(children[iter_index]->getText()) == "distinct")
		{
			iter_index++;
			stmt_p->distinct = true;
		} 
		else if (utils::string_to_lower(children[iter_index]->getText()) == "all")
		{
			iter_index++;
			stmt_p->all = true;
		}
		// iter_index points to first result column
		while (iter_index < children.size())
		{
			// result_columns
			auto result_column_tree = children[iter_index];
			auto result_column_tokens = utils::tokens_from_parse_tree(result_column_tree);
			auto result_column = ChainsqlResultColumn();
			result_column.tokens = result_column_tokens;
			stmt_p->result_columns.push_back(result_column);
			if (iter_index >= children.size() - 1 || utils::string_to_lower(children[iter_index + 1]->getText()) != ",")
				break;
			iter_index += 2;
		}
		iter_index++;
		if (iter_index < children.size() && utils::string_to_lower(children[iter_index]->getText()) == "from")
		{
			// from子句
			iter_index++;
			while (iter_index < children.size())
			{
				auto table_tree = children[iter_index];
				auto table_tokens = utils::tokens_from_parse_tree(table_tree);
				auto table_query = ChainsqlTableQuery();
				table_query.table_name = table_tokens[0];
				if (table_tokens.size() == 2)
				{
					table_query.alias = table_tokens[1];
				}
				else if (table_tokens.size() == 3)
				{
					table_query.alias = table_tokens[2];
				}
				stmt_p->tables.push_back(table_query);
				if (iter_index >= children.size() - 1 || utils::string_to_lower(children[iter_index + 1]->getText()) != ",")
					break;
				iter_index += 2;
			}
			iter_index++;
		}

		if (iter_index < children.size() && utils::string_to_lower(children[iter_index]->getText()) == "where")
		{
			// iter_index points to where keyword
			iter_index++;
			auto condition_tree = children[iter_index];
			auto condition_tokens = utils::tokens_from_parse_tree(condition_tree);
			stmt_p->condition = std::make_shared<ChainsqlExpr>(condition_tokens);
			iter_index++;
		}

		if (iter_index < children.size() - 1 && utils::string_to_lower(children[iter_index]->getText()) == "group" && utils::string_to_lower(children[iter_index + 1]->getText()) == "by")
		{
			// iter_index points to order keyword
			iter_index += 2;
			// iter_index points to first ordering_term
			stmt_p->group_by = std::make_shared<ChainsqlGroupBy>();
			while (iter_index < children.size())
			{
				auto group_by_term_tree = children[iter_index];
				auto group_by_term_tokens = utils::tokens_from_parse_tree(group_by_term_tree);
				auto group_by_exp = ChainsqlExpr(group_by_term_tokens);
				auto ascending = true;
				stmt_p->group_by->exprs.push_back(group_by_exp);
				if (iter_index >= children.size() - 1 || utils::string_to_lower(children[iter_index + 1]->getText()) != ",")
					break;
				iter_index += 2;
			}
			iter_index++;
			if (iter_index < children.size() && utils::string_to_lower(children[iter_index]->getText()) == "having")
			{
				// iter_index points to having keyword
				iter_index++;
				auto having_tree = children[iter_index];
				auto having_tokens = utils::tokens_from_parse_tree(having_tree);
				stmt_p->group_by->having_expr = std::make_shared<ChainsqlExpr>(having_tokens);
				iter_index++;
			}
		}
		if (iter_index < children.size() - 1 && utils::string_to_lower(children[iter_index]->getText()) == "order" && utils::string_to_lower(children[iter_index + 1]->getText()) == "by")
		{
			// iter_index points to order keyword
			iter_index += 2;
			// iter_index points to first ordering_term
			while (iter_index < children.size())
			{
				auto ordering_term_tree = children[iter_index];
				auto ordering_term_tokens = utils::tokens_from_parse_tree(ordering_term_tree);
				auto order_column_name = ordering_term_tokens[0];
				auto ascending = true;
				if (ordering_term_tokens.size() >= 2)
				{
					auto order = utils::string_to_lower(ordering_term_tokens[1]);
					if (order == "desc")
						ascending = false;
					else if (order == "asc")
						ascending = true;
					else
						throw ChainsqlException(std::string("update stmt syntax error, not support index order ") + order);
				}
				stmt_p->orders.push_back(ChainsqlOrderInfo(order_column_name, ascending));
				if (iter_index >= children.size() - 1 || utils::string_to_lower(children[iter_index + 1]->getText()) == "limit")
					break;
				iter_index += 2;
			}
			iter_index ++;
		}

		if(iter_index < children.size() && utils::string_to_lower(children[iter_index]->getText()) == "limit")
		{
			iter_index++;
			// limit
			auto limit_exp = children[iter_index]->getText();
			if (!utils::string_is_digits(limit_exp))
			{
				throw ChainsqlException(std::string("select stmt syntax error, not support limit value ") + limit_exp);
			}
			auto limit = std::stol(limit_exp);
			if (limit < 0)
			{
				throw ChainsqlException(std::string("select stmt syntax error, not support limit value ") + limit_exp);
			}
			iter_index++;
			stmt_p->limit = limit;
			// offset
			if (iter_index < children.size() && utils::string_to_lower(children[iter_index]->getText()) == "offset")
			{
				auto offset_exp = children[iter_index]->getText();
				if (!utils::string_is_digits(offset_exp))
				{
					throw ChainsqlException(std::string("select stmt syntax error, not support offset value ") + offset_exp);
				}
				auto offset = std::stol(offset_exp);
				if (offset < 0)
				{
					throw ChainsqlException(std::string("select stmt syntax error, not support offset value ") + offset_exp);
				}
				iter_index++;
				stmt_p->offset = offset;
			}
		}
	}

	void chainsqlStructureListener::enterUpdate_stmt_limited(chainsqlParser::Update_stmt_limitedContext * /*ctx*/)
	{
		
	}
	void chainsqlStructureListener::exitUpdate_stmt_limited(chainsqlParser::Update_stmt_limitedContext * ctx)
	{
		ChainsqlUpdateStmt *stmt_p = nullptr;
		{
			auto stmt = std::make_unique<ChainsqlUpdateStmt>();
			stmt_p = stmt.get();
			_chainsql_ctx.add_managed_update_stmt(std::move(stmt));
		}
		_chainsql_stmts.push_back(stmt_p);

		const auto &children = ctx->children;
		if (children.size() < 8)
		{
			throw ChainsqlException("update stmt syntax error");
		}
		size_t iter_index = 1;
		// now iter_index points to table_name
		auto table_name = children[iter_index]->getText();
		stmt_p->table_name = table_name;
		iter_index += 2;
		// set columns
		stmt_p->set_columns = std::vector<std::pair<std::string, ChainsqlExpr>>();
		while (iter_index < children.size())
		{
			auto column_name = children[iter_index]->getText();
			auto expr_tree = children[iter_index + 2];
			auto expr_tokens = utils::tokens_from_parse_tree(expr_tree);
			stmt_p->set_columns.push_back(std::make_pair(column_name, ChainsqlExpr(expr_tokens)));
			if (iter_index >= children.size() - 3 || utils::string_to_lower(children[iter_index + 3]->getText()) != ",")
				break;
			iter_index += 4;
		}
		iter_index += 3;
		if (iter_index < children.size() && utils::string_to_lower(children[iter_index]->getText()) == "where")
		{
			// iter_index points to where keyword
			iter_index++;
			auto condition_tree = children[iter_index];
			auto condition_tokens = utils::tokens_from_parse_tree(condition_tree);
			stmt_p->condition = std::make_shared<ChainsqlExpr>(condition_tokens);
			iter_index++;
		}
		if (iter_index < children.size()-1 && utils::string_to_lower(children[iter_index]->getText()) == "order" && utils::string_to_lower(children[iter_index+1]->getText()) == "by")
		{
			// iter_index points to order keyword
			iter_index += 2;
			// iter_index points to first ordering_term
			while (iter_index < children.size())
			{
				auto ordering_term_tree = children[iter_index];
				auto ordering_term_tokens = utils::tokens_from_parse_tree(ordering_term_tree);
				auto order_column_name = ordering_term_tokens[0];
				auto ascending = true;
				if (ordering_term_tokens.size() >= 2)
				{
					auto order = utils::string_to_lower(ordering_term_tokens[1]);
					if (order == "desc")
						ascending = false;
					else if (order == "asc")
						ascending = true;
					else
						throw ChainsqlException(std::string("update stmt syntax error, not support index order ") + order);
				}
				stmt_p->orders.push_back(ChainsqlOrderInfo(order_column_name, ascending));
				if (iter_index >= children.size() - 1 || utils::string_to_lower(children[iter_index + 1]->getText()) == "limit")
					break;
				iter_index += 2;
			}
			iter_index++;
		}
		iter_index++;
		if (iter_index >= children.size())
			throw ChainsqlException("update stmt syntax error");
		auto limit_exp = children[iter_index]->getText();
		if (!utils::string_is_digits(limit_exp))
		{
			throw ChainsqlException(std::string("update stmt syntax error, not support limit value ") + limit_exp);
		}
		auto limit = std::stol(limit_exp);
		if (limit < 0)
		{
			throw ChainsqlException(std::string("update stmt syntax error, not support limit value ") + limit_exp);
		}
		stmt_p->limit = limit;
	}

	void chainsqlStructureListener::enterColumn_def(chainsqlParser::Column_defContext * ctx)
	{
	}
	void chainsqlStructureListener::exitColumn_def(chainsqlParser::Column_defContext * ctx)
	{
		ChainsqlColumnDef column_def;
		const auto &children = ctx->children;
		column_def.column_name = children[0]->getText();
		auto type_name_tree = children[1];
		auto type_name_tokens = utils::tokens_from_parse_tree(type_name_tree);
		if (type_name_tokens.size() == 1 && utils::string_to_lower(type_name_tokens[0]) == "string")
		{
			type_name_tokens[0] = "text";
		}
		column_def.column_type = utils::vector_join(type_name_tokens, "");
		_tmp_column_defs.push_back(column_def);
	}

	void chainsqlStructureListener::enterShow_tables_stmt(chainsqlParser::Show_tables_stmtContext * /*ctx*/)
	{

	}
	
	void chainsqlStructureListener::exitShow_tables_stmt(chainsqlParser::Show_tables_stmtContext *ctx)
	{
		ChainsqlShowTablesStmt *stmt_p = nullptr;
		{
			auto stmt = std::make_unique<ChainsqlShowTablesStmt>();
			stmt_p = stmt.get();
			_chainsql_ctx.add_managed_show_tables_stmt(std::move(stmt));
		}
		_chainsql_stmts.push_back(stmt_p);
	}

	void chainsqlStructureListener::enterExpr(chainsqlParser::ExprContext * /*ctx*/)
	{

	}
	void chainsqlStructureListener::exitExpr(chainsqlParser::ExprContext * ctx)
	{
		auto tokens = utils::tokens_from_parse_tree(ctx);
		if (tokens.size() >= 3)
		{
			for (size_t i = 0; i < tokens.size(); i++)
			{
				if (tokens[i] == "(")
				{
					if (i > 0)
					{
						auto func_name = tokens[i - 1];
						if (std::find(chainsql_allowed_expr_functions.begin(), chainsql_allowed_expr_functions.end(), utils::string_to_lower(func_name))== chainsql_allowed_expr_functions.end())
						{
							// chainsql函数名不在白名单中
							throw ChainsqlException(std::string("not allowed chainsql function name ") + func_name);
						}
					}
				}
			}
		}
	}

	void chainsqlStructureListener::enterType_name(chainsqlParser::Type_nameContext * /*ctx*/)
	{
	}
	void chainsqlStructureListener::exitType_name(chainsqlParser::Type_nameContext * ctx)
	{
		auto tokens = utils::tokens_from_parse_tree(ctx);
		if (tokens.empty())
			throw ChainsqlException("type name can't be empty");
		auto base_type_name = tokens[0];
		if (std::find(chainsql_allowed_column_types.begin(), chainsql_allowed_column_types.end(), utils::string_to_lower(base_type_name)) == chainsql_allowed_column_types.end())
		{
			// chainsql 字段类型名称不在白名单中
			throw ChainsqlException(std::string("not allowed chainsql column type name ") + utils::vector_join(tokens, ","));
		}
	}

	void chainsqlStructureListener::enterColumn_name(chainsqlParser::Column_nameContext * /*ctx*/)
	{
	}
	void chainsqlStructureListener::exitColumn_name(chainsqlParser::Column_nameContext * ctx)
	{
		auto tokens = utils::tokens_from_parse_tree(ctx);
		if (tokens.size() != 1)
			throw ChainsqlException("chainsql column name must be one token");
		auto column_name = tokens[0];
		if (std::find(chainsql_disabled_column_names.begin(), chainsql_disabled_column_names.end(), utils::string_to_lower(column_name)) != chainsql_disabled_column_names.end())
		{
			// chainsql字段名称在黑名单中
			throw ChainsqlException(std::string("not allowed chainsql column name ") + column_name);
		}
	}
	
}
