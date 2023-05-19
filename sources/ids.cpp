#include "algorithm.h"

std::vector<std::string> iterativeDeepeningDFS(const std::string& source, const std::string& destination) {
    int depthLimit = 0;
    while (true) {
        std::vector<std::string> path = depthLimitedSearch(source, destination, depthLimit);
        if (!path.empty()) {
            return path;
        }
        depthLimit++;
    }
}