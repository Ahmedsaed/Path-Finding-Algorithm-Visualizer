#include "algorithm.h"

/**
 * @brief Finds the shortest path between two nodes in a graph using breadth-first search algorithm
 * 
 * @param source The starting node
 * @param destination The destination node
 * @param romania The graph represented as an adjacency list
 * @return The shortest path from source to destination as a vector of node names, or an empty vector if no path is found
 * 
 * This function implements the breadth-first search algorithm to find the shortest path between two nodes in a graph represented as an adjacency list. It takes the starting node, destination node, and the graph as input parameters and returns the shortest path as a vector of node names. If no path is found, it returns an empty vector.
 * 
 * The algorithm works by maintaining a queue of nodes to be explored, a set of visited nodes, and a map of parent nodes. It starts by adding the source node to the queue and the visited set and then explores the neighbors of the source node. For each neighbor, it enqueues it if it has not been visited before and marks it as visited. It also sets the parent of the neighbor to the current node.
 * 
 * The algorithm continues to explore the graph by dequeuing the front node from the queue and expanding its neighbors. It enqueues the unvisited neighbors and marks them as visited. It also sets their parent to the current node. The algorithm terminates when it reaches the destination node or the queue becomes empty.
 * 
 * If the destination node is reached, the function constructs the shortest path from the source to the destination node by backtracking from the destination node to the source using the parent nodes. The final path is returned as a vector of node names.
 * 
 * If no path is found, the function returns an empty vector.
 */
udtl::vector<std::string> breadthFirstSearch(const std::string& source, const std::string& destination) {
    udtl::queue<std::string> q;
    std::set<std::string> visited;
    std::map<std::string, std::string> parent;

    q.push(source);
    visited.insert(source);

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        if (current == destination) {
            udtl::vector<std::string> path;
            std::string node = current;
            while (node != source) {
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(source);
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& neighbor : romania[current]) {
            if (visited.find(neighbor.first) == visited.end()) {
                q.push(neighbor.first);
                visited.insert(neighbor.first);
                parent[neighbor.first] = current;
            }
        }
    }

    return {};
}
