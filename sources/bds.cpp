#include "algorithm.h"

/**
 * @brief Finds the shortest path between two nodes in a graph using bidirectional breadth-first search
 * 
 * @param source The starting node
 * @param destination The destination node
 * @param romania The graph represented as an adjacency list
 * @return The shortest path from source to destination as a vector of node names, or an empty vector if no path is found
 * 
 * This function implements the bidirectional breadth-first search algorithm to find the shortest path between two nodes in a graph represented as an adjacency list. It takes the starting node, destination node, and the graph as input parameters and returns the shortest path as a vector of node names. If no path is found, it returns an empty vector.
 * 
 * The algorithm works by simultaneously exploring the graph from both the source and destination nodes until they meet at a common node. It maintains two sets of visited nodes, one from the source and the other from the destination, and two sets of parent nodes, one for each direction. It also maintains two queues, one for each direction, to keep track of the nodes to be explored.
 * 
 * The algorithm starts by adding the source and destination nodes to their respective queues and visited sets. It then explores the nodes in both directions by dequeuing the front nodes from the queues and expanding their neighbors. If a node is visited from the opposite direction, it means that the two paths have met at that node, and the algorithm terminates. Otherwise, it continues to explore the graph until it finds a meeting node.
 * 
 * Once a meeting node is found, the algorithm constructs the shortest path from the source to the meeting node by backtracking from the meeting node to the source using the parent nodes. It then extends the path from the meeting node to the destination using the parent nodes in the opposite direction. The final path is returned as a vector of node names.
*/
udtl::vector<std::string> bidirectionalSearch(const std::string& source, const std::string& destination) {
    std::map<std::string, bool> visitedFromSource;
    std::map<std::string, bool> visitedFromDestination;

    std::map<std::string, std::string> parentFromSource;
    std::map<std::string, std::string> parentFromDestination;

    udtl::queue<std::string> qSource;
    udtl::queue<std::string> qDestination;

    qSource.push(source);
    visitedFromSource[source] = true;

    qDestination.push(destination);
    visitedFromDestination[destination] = true;

    std::string meetingNode;

    while (!qSource.empty() && !qDestination.empty()) {
        std::string currentSource = qSource.front();
        qSource.pop();

        std::string currentDestination = qDestination.front();
        qDestination.pop();

        // Check if the current nodes from both directions meet
        if (visitedFromDestination.find(currentSource) != visitedFromDestination.end()) {
            meetingNode = currentSource;
            break;
        }

        if (visitedFromSource.find(currentDestination) != visitedFromSource.end()) {
            meetingNode = currentDestination;
            break;
        }

        // Expand nodes in the source direction
        for (const auto& neighbor : romania[currentSource]) {
            if (visitedFromSource.find(neighbor.first) == visitedFromSource.end()) {
                qSource.push(neighbor.first);
                visitedFromSource[neighbor.first] = true;
                parentFromSource[neighbor.first] = currentSource;
            }
        }

        // Expand nodes in the destination direction
        for (const auto& neighbor : romania[currentDestination]) {
            if (visitedFromDestination.find(neighbor.first) == visitedFromDestination.end()) {
                qDestination.push(neighbor.first);
                visitedFromDestination[neighbor.first] = true;
                parentFromDestination[neighbor.first] = currentDestination;
            }
        }
    }

    if (meetingNode.empty()) {
        return {};  // No path found
    }

    // Construct the path from the source to the meeting node
    udtl::vector<std::string> path;
    std::string node = meetingNode;
    while (node != source) {
        path.push_back(node);
        node = parentFromSource[node];
    }
    path.push_back(source);
    std::reverse(path.begin(), path.end());

    // Extend the path from the meeting node to the destination
    node = meetingNode;
    while (node != destination) {
        node = parentFromDestination[node];
        path.push_back(node);
    }

    return path;
}
