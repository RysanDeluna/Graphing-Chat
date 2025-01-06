// Graphing.cpp: define o ponto de entrada para o aplicativo.
//

#include <iostream>
#include <string>
#include "BotParser.h"


int main()
{
	BotParser parser("C:/Users/ryanm/source/repos/Graphing/rsc/bot.json");
	parser.checkStructure(9);
	return 0;
}