#pragma once

#include "Graph.h"
#include "JsonParser.h"

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