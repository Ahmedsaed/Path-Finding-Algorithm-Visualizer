#include "algorithm.h"

std::vector<std::string> bidirectionalSearch(const std::string& source, const std::string& destination) {
    std::map<std::string, bool> visitedFromSource;
    std::map<std::string, bool> visitedFromDestination;

    std::map<std::string, std::string> parentFromSource;
    std::map<std::string, std::string> parentFromDestination;

    std::queue<std::string> qSource;
    std::queue<std::string> qDestination;

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
    std::vector<std::string> path;
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
