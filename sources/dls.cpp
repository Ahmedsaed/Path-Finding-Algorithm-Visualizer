#include "algorithm.h"

/**
 * @brief Performs depth-limited search to find the shortest path between two nodes in a graph
 * 
 * @param source The starting node
 * @param destination The destination node
 * @param limit The maximum depth to search
 * @return The shortest path from source to destination as a vector of node names, or an empty vector if no path is found
 * 
 * This function implements the depth-limited search algorithm to find the shortest path between two nodes in a graph. It takes the starting node, destination node, and the maximum depth to search as input parameters and returns the shortest path as a vector of node names. If no path is found, it returns an empty vector.
 * 
 * The algorithm works by maintaining a stack of nodes to be explored, a set of visited nodes, and a map of parent nodes. It starts by adding the source node to the stack and the visited set and then explores its neighbors. For each neighbor, it recursively performs depth-limited search with a reduced depth limit and checks if the destination node is found. If the destination node is found, it constructs the shortest path from the source to the destination node by backtracking from the destination node to the source using the parent nodes. The final path is returned as a vector of node names.
 * 
 * The depth limit is gradually increased until the destination node is found or the maximum depth is reached. The function sets the maximum depth to the maximum integer value if it is not provided.
 * 
 * If no path is found, the function returns an empty vector.
 */
udtl::vector<std::string> depthLimitedSearch(const std::string& source, const std::string& destination, int limit) {
    udtl::stack<std::pair<std::string, int>> st;
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
