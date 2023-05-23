#include "algorithm.h"

udtl::vector<std::string> depthFirstSearch(const std::string& source, const std::string& destination) {
    udtl::vector<std::string> path = depthLimitedSearch(source, destination, 0);
    return (path);
}