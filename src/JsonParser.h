#pragma once
#include <fstream>
#include <string>
#include <map>
#include <stack>
#include <unordered_set>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/*
	Static class that parses through json files
*/
class JsonParser {
private:
	static void _checkStructure(const json& j, std::map<unsigned int, std::unordered_set<std::string>>& showed, int maxDepth, int depth);
public:
	JsonParser() = delete;
	static json readJson(std::string file);
	static void printJson(const json& );
	static void checkStructure(const json& , int depth);
	static const json findKey(const json&, std::string);
};