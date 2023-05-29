#include "algorithm.h"

udtl::vector<std::string> iterativeDeepeningDFS(const std::string& source, const std::string& destination) {
    int depthLimit = 1;
    while (true) {
        udtl::vector<std::string> path = depthLimitedSearch(source, destination, depthLimit);
        if (!path.empty()) {
            return path;
        }
        depthLimit++;
    }
}
