// Graphing.cpp: define o ponto de entrada para o aplicativo.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "BotParser.h"
#include "JsonParser.h"


int main()
{
	int c = 0;
	BotParser bot("C:/Users/ryanm/source/repos/Graphing/rsc/bot.json");
	do
	{
		JsonParser::checkStructure(bot.getJson(), c);
		std::cout << *bot.findKey("data") << std::endl;
		//std::cout << bot.getJson()["groups"][0]["blocks"].is_object() << std::endl;
		//std::cout << bot.getJson()["groups"][0]["blocks"]["drawflow"].is_object() << std::endl;
		//std::cout << bot.getJson()["groups"][0]["blocks"]["drawflow"]["Home"]["data"].is_object() << std::endl;
		//std::cout << *bot.getJson()["groups"][0]["blocks"]["drawflow"]["Home"]["data"].find("16") << std::endl;
		//std::cout << *bot.getJson()["groups"][0]["blocks"]["drawflow"]["Home"]["data"].find("id") << std::endl;

		std::cin >> c;
		system("CLS");
	} while (c != 0);

	return 0;
}