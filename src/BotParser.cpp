#include <iostream>
#include "BotParser.h"

BotParser::BotParser(std::string file)
{
	std::ifstream f(file);
	botJson = json::parse(f);
}

void BotParser::printJson()
{
	std::cout << botJson.dump(4); 
}

void BotParser::readJson(std::string file)
{
	std::fstream f(file);
	botJson = json::parse(f);
}

void BotParser::_checkStructure(json j, int maxDepth = -1, int depth = 0)
{
	const std::string indent = "  ";
	const std::string branch = "|-- "; // Alternativa para ├──
	const std::string lastBranch = "\\__ "; // Alternativa para └──

	if (depth >= maxDepth) return; 
	for (auto& el : j.items())
	{
		std::cout << std::string(depth * indent.size(), ' ') <<
			(std::next(el) == j.items().end() ? lastBranch : branch) << el.key() << std::endl;
		if (el.value().is_object() || el.value().is_array())
			_checkStructure(el.value(), maxDepth, depth + 1);
	}
}

void BotParser::checkStructure(int depth)
{
	json j = botJson;
	_checkStructure(j, depth);
}

Graph BotParser::generateGraph()
{

	return Graph(0);
}

