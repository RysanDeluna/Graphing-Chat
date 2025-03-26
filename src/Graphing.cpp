// Graphing.cpp: define o ponto de entrada para o aplicativo.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "BotParser.h"
#include "JsonParser.h"


int main()
{
	std::string caminho;
	BotParser bot("");

	std::cout << "Bem vindo ao visualizador de JSONs ;)" << std::endl;
	std::cout << "Para utilizá-lo, primeiramente informe o caminho ABSOLUTO do JSON no formato \"C:/Users/Cliente\"\n";

	while(bot.getJson().empty()) 
	{
		std::cout << "-> ";
		std::cin >> caminho; bot.set_bot(caminho);
		std::cout << "\n";
	}

	std::cout << "ARQUIVO IDENTIFICADO COM SUCESSO\n" << std::endl;

	int c = 0;
	do
	{
		std::cout << "Qual o nível de visualização desejado? (Digite apenas números)\n";
		std::cout << "Para fechar o programa, digite '0'\n";
		std::cin >> c;
		JsonParser::checkStructure(bot.getJson(), c);
		//std::cout << bot.findKey("164");
		//std::cout << bot.getJson()["groups"][0]["blocks"].is_object() << std::endl;
		//std::cout << bot.getJson()["groups"][0]["blocks"]["drawflow"].is_object() << std::endl;
		//std::cout << bot.getJson()["groups"][0]["blocks"]["drawflow"]["Home"]["data"].is_object() << std::endl;
		//*bot.getJson()["groups"][55]["blocks"]["drawflow"]["Home"]["data"].find("164") << std::endl;
		//std::cout << *bot.getJson()["groups"][0]["blocks"]["drawflow"]["Home"]["data"].find("id") << std::endl;

		system("CLS");
	} while (c != 0);

	return 0;
}