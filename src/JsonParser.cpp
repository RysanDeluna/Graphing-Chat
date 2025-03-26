#include "JsonParser.h"
#include <iostream>

void JsonParser::printJson(const json& j)
{
	std::cout << j.dump(4);
}

json JsonParser::readJson(std::string file)
{
	std::fstream f(file);
	if (f.is_open())
		return json::parse(f);
	return json();
}

void JsonParser::_checkStructure(const json& j, std::map<unsigned int, std::unordered_set<std::string>>& showed, int maxDepth = -1, int depth = 0)
{
	const std::string indent = "  ";
	const std::string branch = "|-- "; // Alternativa para ├──
	const std::string lastBranch = "\\__ "; // Alternativa para └──


	if (depth >= maxDepth) return;
	for (auto& el : j.items())
	{
		if (showed[depth].find(el.key()) != showed[depth].end())
			continue;
		showed[depth].insert(el.key());

		std::cout << std::string(depth * indent.size(), ' ') <<
			(std::next(el) == j.items().end() ? lastBranch : branch) << el.key() << std::endl;
		if (el.value().is_object() || el.value().is_array())
			_checkStructure(el.value(), showed, maxDepth, depth + 1);
	}
}

void JsonParser::checkStructure(const json& j, int depth)
{
	std::map<unsigned int, std::unordered_set<std::string>> showed;
	for (int i = 1; i <= depth; i++)
		showed.insert(std::pair<int, std::unordered_set<std::string>>(i, std::unordered_set<std::string>()));
	_checkStructure(j, showed, depth, 0);
}

const json JsonParser::findKey(const json& j, std::string key)
{
	std::stack<std::shared_ptr<json>> st;
	std::shared_ptr<json> p_j = std::make_shared<json>(j);
	st.push(p_j);
	do {
		auto it = p_j->find(key);
		if (it != p_j->end()) 
			return *it;
		for (auto& el : p_j->items())
		{
			json temp = el.value(); 
			if (temp.is_object() || temp.is_array())
				st.push(std::make_shared<json>(temp));
		}
		p_j.swap(st.top());
		st.pop();
	} while (!st.empty());
	return nullptr;
}
