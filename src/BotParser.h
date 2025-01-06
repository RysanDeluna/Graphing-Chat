#pragma once

#include "Graph.h"
#include "JsonParser.h"

class BotParser {
private:
	int numIntents;
	json botJson;

public:
	BotParser(std::string file);
	~BotParser() = default;

	Graph generateGraph();
};