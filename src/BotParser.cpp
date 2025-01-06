#include <iostream>
#include "BotParser.h"

BotParser::BotParser(std::string file)
{
	botJson = JsonParser::readJson(file);
}

Graph BotParser::generateGraph()
{

	return Graph(0);
}

