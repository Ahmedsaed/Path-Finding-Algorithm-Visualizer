#include "algorithm.h"

std::vector<std::string> depthFirstSearch(const std::string& source, const std::string& destination) {
    std::vector<std::string> path = depthLimitedSearch(source, destination, 0);
    return (path);
}