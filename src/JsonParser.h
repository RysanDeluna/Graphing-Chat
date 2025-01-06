#pragma once
#include <fstream>
#include <string>
#include <map>
#include <unordered_set>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class JsonParser {
private:
	static void _checkStructure(json j, std::map<unsigned int, std::unordered_set<std::string>>& showed, int maxDepth, int depth);

public:
	JsonParser() = delete;
	static json readJson(std::string file);
	static void printJson(json j);
	static void checkStructure(json j, int depth);
};