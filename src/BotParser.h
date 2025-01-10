#pragma once

#include "Graph.h"
#include "JsonParser.h"


/*
	Have the Bot Json file and will be responsible
	to do operations and retrieve information from it
*/
class BotParser {
private:
	int numIntents;
	json botJson;
	Graph generateGraph();

public:
	BotParser(std::string file);
	~BotParser() = default;
	
	// Getter
	const json getJson();

	// Operations
	const json::iterator findKey(std::string);
	std::list<json::iterator> findKeys(std::string, const json&);
};