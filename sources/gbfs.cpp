#include "algorithm.h"
#include <queue>

/**
 * @brief Finds the shortest path between two nodes in a graph using greedy best-first search algorithm
 * 
 * @param source The starting node
 * @param destination The destination node
 * @param romania The graph represented as an adjacency list
 * @param H_table The heuristic table containing the estimated distances from each node to the destination node
 * @return The shortest path from source to destination as a vector of node names, or an empty vector if no path is found
 * 
 * This function implements the greedy best-first search algorithm to find the shortest path between two nodes in a graph represented as an adjacency list. It takes the starting node, destination node, the graph, and the heuristic table as input parameters and returns the shortest path as a vector of node names. If no path is found, it returns an empty vector.
 * 
 * The algorithm works by maintaining a priority queue ordered by the heuristic value, which is the estimated distance from the current node to the destination node. It also maintains two maps, one for visited nodes and the other for parent nodes. It starts by enqueuing the source node with its heuristic value as priority and marks it as visited. 
 * 
 * The algorithm dequeues the node with the lowest heuristic value from the priority queue and explores its neighbors. For each unvisited neighbor, it enqueues it with its heuristic value as priority and marks it as visited. It also sets its parent to the current node.
 * 
 * The algorithm continues to explore the graph until it reaches the destination node or the priority queue becomes empty. If the destination node is reached, it constructs the shortest path from the source to the destination node by backtracking from the destination node to the source using the parent nodes. The final path is returned as a vector of node names.
 * 
 * If no path is found, the function returns an empty vector.
 */
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
