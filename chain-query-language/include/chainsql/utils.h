#pragma once

#include <antlr4-runtime.h>
#include <string>
#include <vector>

namespace chainsql
{
	namespace utils
	{
		using namespace antlr4;

		std::vector<std::string> tokens_from_parse_tree(tree::ParseTree *tr);

		std::string vector_join(const std::vector<std::string> &items, std::string sep = "");

		std::string string_to_lower(std::string src);

		bool string_is_digits(std::string str);
	}
}
