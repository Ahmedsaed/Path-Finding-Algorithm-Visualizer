#include "algorithm.h"

using namespace std;

udtl::vector<std::string> uniformCostSearch(const std::string& source, const std::string& destination) {
    std::map<std::string, bool> visited;
    std::map<std::string, int> cost;
    std::map<std::string, std::string> parent;
    std::priority_queue<std::pair<int, std::string>, udtl::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> pq;

    // Initialize cost and visited arrays
    for (const auto& city : romania) {
        cost[city.first] = std::numeric_limits<int>::max();
        visited[city.first] = false;
    }

    cost[source] = 0;
    pq.push(std::make_pair(0, source));

    while (!pq.empty()) {
        std::string current = pq.top().second;
        pq.pop();

        if (current == destination)
            break;

        if (visited[current])
            continue;

        visited[current] = true;

        for (const auto& neighbor : romania[current]) {
            std::string nextCity = neighbor.first;
            int edgeCost = neighbor.second;

            if (!visited[nextCity] && cost[current] + edgeCost < cost[nextCity]) {
                cost[nextCity] = cost[current] + edgeCost;
                parent[nextCity] = current;
                pq.push(std::make_pair(cost[nextCity], nextCity));
            }
        }
    }

    // Reconstruct the path from destination to source
    udtl::vector<std::string> path;
    std::string current = destination;

    while (current != source) {
        path.insert(path.begin(), current);
        current = parent[current];
    }

    path.insert(path.begin(), source);

    return path;
}