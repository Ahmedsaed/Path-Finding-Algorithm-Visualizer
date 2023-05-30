#ifndef ALGO_H
#define ALGO_H

#include "main.h"

#include "vector.h"
#include <set>
#include <map>
#include "queue.h"
#include "stack.h"
#include "priority_queue.h"
#include <algorithm>
#include <QStringList>
#include <queue>

extern std::map<std::string, std::vector<std::pair<std::string, int>>> romania;
extern std::map<std::string, int> H_table;

udtl::vector<std::string> uniformCostSearch(const std::string& source, const std::string& destination);
udtl::vector<std::string> depthLimitedSearch(const std::string& source, const std::string& destination, int limit = 0);
udtl::vector<std::string> iterativeDeepeningDFS(const std::string& source, const std::string& destination);
udtl::vector<std::string> breadthFirstSearch(const std::string& source, const std::string& destination);
udtl::vector<std::string> depthFirstSearch(const std::string& source, const std::string& destination);
udtl::vector<std::string> bidirectionalSearch(const std::string& source, const std::string& destination);
udtl::vector<std::string> greedyBFS(const std::string& source, const std::string& destination);
udtl::vector<std::string> AStarSearch(const std::string& source, const std::string& destination);

#endif
