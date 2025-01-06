#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include "Graph.h"

using json = nlohmann::json;

class BotParser {
private:
	int numIntents;
	json botJson;

	void _checkStructure(json j, int maxDepth, int depth);

public:
	BotParser(std::string file);
	~BotParser() = default;

	void printJson();
	void readJson(std::string file);
	void checkStructure(int depth);
	Graph generateGraph();
};