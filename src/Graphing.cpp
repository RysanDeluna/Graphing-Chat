// Graphing.cpp: define o ponto de entrada para o aplicativo.
//

#include <iostream>
#include <string>
#include "BotParser.h"
#include "JsonParser.h"


int main()
{
	auto j = JsonParser::readJson("C:/Users/ryanm/source/repos/Graphing/rsc/bot.json");
	JsonParser::checkStructure(j, 2);
	return 0;
}