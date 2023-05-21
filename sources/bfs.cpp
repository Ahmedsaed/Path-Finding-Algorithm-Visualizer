#include "algorithm.h"

std::vector<std::string> breadthFirstSearch(const std::string& source, const std::string& destination) {
    std::queue<std::string> q;
    std::set<std::string> visited;
    std::map<std::string, std::string> parent;

    q.push(source);
    visited.insert(source);

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        if (current == destination) {
            std::vector<std::string> path;
            std::string node = current;
            while (node != source) {
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(source);
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& neighbor : rome[current]) {
            if (visited.find(neighbor.first) == visited.end()) {
                q.push(neighbor.first);
                visited.insert(neighbor.first);
                parent[neighbor.first] = current;
            }
        }
    }

    return {};
}