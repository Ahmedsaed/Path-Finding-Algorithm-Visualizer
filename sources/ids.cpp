#include "algorithm.h"

/**
 * @brief Finds the shortest path between two nodes in a graph using iterative deepening depth-first search algorithm
 * 
 * @param source The starting node
 * @param destination The destination node
 * @param romania The graph represented as an adjacency list
 * @return The shortest path from source to destination as a vector of node names, or an empty vector if no path is found
 * 
 * This function implements the iterative deepening depth-first search algorithm to find the shortest path between two nodes in a graph represented as an adjacency list. It takes the starting node, destination node, and the graph as input parameters and returns the shortest path as a vector of node names. If no path is found, it returns an empty vector.
 * 
 * The algorithm works by repeatedly performing depth-limited search with increasing depth limits until the destination node is found or the maximum depth is reached. It starts by performing depth-limited search with a depth limit of 1, which only explores the immediate neighbors of the source node. If the destination node is not found at this depth, the algorithm increases the depth limit and performs depth-limited search again. It continues to increase the depth limit and perform depth-limited search until the destination node is found or the maximum depth is reached.
 * 
 * The function calls the depthLimitedSearch() function with increasing depth limits until a path is found or the maximum depth is reached. If a path is found, it is returned as a vector of node names. If no path is found, the function returns an empty vector.
 */
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