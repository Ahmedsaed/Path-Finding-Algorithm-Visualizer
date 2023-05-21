#ifndef ALGO_H
#define ALGO_H

#include "main.h"

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

extern std::map<std::string, std::vector<std::pair<std::string, int>>> rome;

std::vector<std::string> uniformCostSearch(const std::string& source, const std::string& destination);
std::vector<std::string> depthLimitedSearch(const std::string& source, const std::string& destination, int limit = 0);
std::vector<std::string> iterativeDeepeningDFS(const std::string& source, const std::string& destination);
std::vector<std::string> breadthFirstSearch(const std::string& source, const std::string& destination);
std::vector<std::string> depthFirstSearch(const std::string& source, const std::string& destination);

#endif
