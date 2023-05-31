#include "algorithm.h"
#include <queue>

/**
 * @brief Finds the shortest path between two nodes in a graph using A* search algorithm
 *
 * @param source The starting node
 * @param destination The destination node
 * @param romania The graph represented as an adjacency list
 * @param H_table The heuristic table containing the estimated distances from each node to the destination node
 * @return The shortest path from source to destination as a vector of node names, or an empty vector if no path is found
 *
 * This function implements the A* search algorithm to find the shortest path between two nodes in a graph represented as an adjacency list. It takes the starting node, destination node, the graph, and the heuristic table as input parameters and returns the shortest path as a vector of node names. If no path is found, it returns an empty vector.
 *
 * The algorithm works by maintaining two maps, one for visited nodes and the other for parent nodes, and two maps for the cost from the start node to the current node and the estimated cost from the start node to the destination node through the current node. It also maintains a priority queue ordered by the fScore, which is the sum of the gScore and the heuristic value.
 *
 * The algorithm starts by initializing the scores for all nodes to infinity except for the source node, which is set to 0 for gScore and the heuristic value for fScore. It then enqueues the source node with its fScore as priority and marks it as visited.
 *
 * The algorithm dequeues the node with the lowest fScore from the priority queue and explores its neighbors. For each neighbor, it calculates the tentative gScore as the sum of the gScore of the current node and the weight of the edge connecting them. If the tentative gScore is lower than the gScore of the neighbor, it updates the scores and enqueues the neighbor with its fScore as priority. It also marks the neighbor as visited and sets its parent to the current node.
 *
 * The algorithm continues to explore the graph until it reaches the destination node or the priority queue becomes empty. If the destination node is reached, it constructs the shortest path from the source to the destination node by backtracking from the destination node to the source using the parent nodes. The final path is returned as a vector of node names.
 *
 * If no path is found, the function returns an empty vector.
*/
udtl::vector<std::string> AStarSearch(const std::string& source, const std::string& destination) {
    std::map<std::string, bool> visited;
    std::map<std::string, std::string> parent;
    std::map<std::string, int> gScore; // Cost from start to current node
    std::map<std::string, int> fScore; // Cost from start to current node + heuristic value

    // Priority queue ordered by the fScore
    std::priority_queue<std::pair<int, std::string>, udtl::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> pq;

    // Initialize scores for all cities to infinity except for the source city
    for (const auto& pair : romania) {
        std::string city = pair.first;
        gScore[city] = std::numeric_limits<int>::max();
        fScore[city] = std::numeric_limits<int>::max();
    }
    gScore[source] = 0;
    fScore[source] = H_table[source];

    // Enqueue the source city with its fScore as priority
    pq.push({fScore[source], source});
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
                fScore[nextCity] = gScore[nextCity] + H_table[nextCity];
                pq.push({fScore[nextCity], nextCity});
            }
        }
    }

    // No path found
    return {};
}
