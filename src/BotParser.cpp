﻿#include <iostream>
#include "BotParser.h"

Graph BotParser::generateGraph()
{
	return Graph(0);
}


BotParser::BotParser(std::string file)
{
	botJson = JsonParser::readJson(file);
	generateGraph();
}

const json BotParser::getJson()
{
	return botJson;
}

const json BotParser::findKey(std::string key)
{
	return JsonParser::findKey(botJson, key);
}

void BotParser::set_bot(std::string file) 
{
	botJson = JsonParser::readJson(file);
	generateGraph();
}


