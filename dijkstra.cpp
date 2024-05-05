#include "algorithm.h"

udtl::vector<std::string> DijkstraSearch(const std::string& source, const std::string& destination) {
    std::map<std::string, bool> visited;
    std::map<std::string, std::string> parent;
    std::map<std::string, int> gScore; // Cost from start to current node

    // Priority queue ordered by the gScore
    std::priority_queue<std::pair<int, std::string>, udtl::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> pq;

    // Initialize scores for all cities to infinity except for the source city
    for (const auto& pair : romania) {
        std::string city = pair.first;
        gScore[city] = std::numeric_limits<int>::max();
    }
    gScore[source] = 0;

    // Enqueue the source city with its gScore as priority
    pq.push({gScore[source], source});
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
            int edgeWeight = neighbor.second;

            int tentativeGScore = gScore[currentCity] + edgeWeight;
            if (tentativeGScore < gScore[nextCity]) {
                visited[nextCity] = true;
                parent[nextCity] = currentCity;
                gScore[nextCity] = tentativeGScore;
                pq.push({gScore[nextCity], nextCity});
            }
        }
    }

    // No path found
    return {};
}
