#include <chainsql/utils.h>
#include <sstream>
#include <algorithm>

namespace chainsql
{
	namespace utils
	{
		std::vector<std::string> tokens_from_parse_tree(tree::ParseTree *tr)
		{
			std::vector<std::string> tokens;
			auto children = tr->children;

			if (children.empty())
			{
				auto text = tr->getText();
				if (!text.empty())
					tokens.push_back(text);
			}
			for (const auto &item : children)
			{
				auto sub_tokens = tokens_from_parse_tree(item);
				for (const auto &sub_token : sub_tokens)
					tokens.push_back(sub_token);
			}
			return tokens;
		}

		std::string vector_join(const std::vector<std::string> &items, std::string sep)
		{
			std::stringstream ss;
			for (size_t i = 0; i < items.size(); i++)
			{
				if (i > 0)
					ss << sep;
				ss << items[i];
			}
			return ss.str();
		}

		std::string string_to_lower(std::string src)
		{
			std::string data(src);
			std::transform(data.begin(), data.end(), data.begin(), ::tolower);
			return data;
		}

		bool string_is_digits(std::string str)
		{
			if (str.empty())
				return false;
			for (const char c : str)
			{
				if (c<'0' || c > '9')
					return false;
			}
			return true;
		}
	}
}
