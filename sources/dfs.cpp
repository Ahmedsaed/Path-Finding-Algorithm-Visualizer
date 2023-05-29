#include "algorithm.h"

/**
 * @brief Finds the shortest path between two nodes in a graph using iterative deepening depth-first search algorithm
 * 
 * @param source The starting node
 * @param destination The destination node
 * @param maxDepth The maximum depth to search
 * @return The shortest path from source to destination as a vector of node names, or an empty vector if no path is found
 * 
 * This function implements the iterative deepening depth-first search algorithm to find the shortest path between two nodes in a graph. It takes the starting node, destination node, and the maximum depth to search as input parameters and returns the shortest path as a vector of node names. If no path is found, it returns an empty vector.
 * 
 * The algorithm works by repeatedly performing depth-limited search with increasing depth limits until the destination node is found or the maximum depth is reached. It starts by performing depth-limited search with a depth limit of 0, which only explores the source node. If the destination node is not found at this depth, the algorithm increases the depth limit and performs depth-limited search again. It continues to increase the depth limit and perform depth-limited search until the destination node is found or the maximum depth is reached.
 * 
 * The depth-limited search algorithm works by maintaining a stack of nodes to be explored, a set of visited nodes, and a map of parent nodes. It starts by adding the source node to the stack and the visited set and then explores its neighbors. For each neighbor, it recursively performs depth-limited search with a reduced depth limit and checks if the destination node is found. If the destination node is found, it constructs the shortest path from the source to the destination node by backtracking from the destination node to the source using the parent nodes. The final path is returned as a vector of node names.
 * 
 * If no path is found, the function returns an empty vector.
 */
udtl::vector<std::string> depthFirstSearch(const std::string& source, const std::string& destination) {
    udtl::vector<std::string> path = depthLimitedSearch(source, destination, 0);
    return (path);
}