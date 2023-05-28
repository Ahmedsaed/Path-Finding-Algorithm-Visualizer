#include "algorithm.h"
#include <queue>

udtl::vector<std::string> greedyBFS(const std::string& source, const std::string& destination) {
    std::map<std::string, bool> visited;
    std::map<std::string, std::string> parent;

    // Priority queue ordered by the heuristic value (greedy approach)
    std::priority_queue<std::pair<int, std::string>, udtl::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> pq;

    // Enqueue the source city with its heuristic value as priority
    pq.push({H_table[source], source});
    visited[source] = true;

    while (!pq.empty()) {
        std::string currentCity = pq.top().second;
        pq.pop();

        if (currentCity == destination) {
            // Destination city reached, construct the path and return
            udtl::vector<std::string> path;
            while (currentCity != source) {
                path.push_back(currentCity);
                currentCity = parent[currentCity];
            }
            path.push_back(source);
            std::reverse(path.begin(), path.end());
            return path;
        }

        // Explore the neighbors of the current city
        for (const auto& neighbor : romania[currentCity]) {
            std::string nextCity = neighbor.first;

            if (!visited[nextCity]) {
                visited[nextCity] = true;
                parent[nextCity] = currentCity;
                pq.push({H_table[nextCity], nextCity});
            }
        }
    }

    // No path found
    return {};
}
