#include "algorithm.h"

std::vector<std::string> depthLimitedSearch(const std::string& source, const std::string& destination, int limit) {
    std::stack<std::pair<std::string, int>> st;
    std::set<std::string> visited;
    std::map<std::string, std::string> parent;

    if (limit == 0)
        limit = std::numeric_limits<int>::max();

    st.push({source, 1});
    visited.insert(source);

    while (!st.empty()) {
        std::string current = st.top().first;
        int depth = st.top().second;
        st.pop();

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

        if (depth < limit) {
            for (const auto& neighbor : romania[current]) {
                if (visited.find(neighbor.first) == visited.end()) {
                    st.push({neighbor.first, depth + 1});
                    visited.insert(neighbor.first);
                    parent[neighbor.first] = current;
                }
            }
        }
    }

    return {};
}