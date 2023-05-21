#include "main.h"
#include "romania.h"
#include "algorithm.h"

using namespace std;

void printPath(vector<string> path);

int main(void)
{
	string start, end, algorithm;

	cout << "Romania Map" << endl;
	cout << "- Arad" << endl
		 << "- Zerind" << endl
		 << "- Oradea" << endl
		 << "- Sibiu" << endl
		 << "- Timisoara" << endl
		 << "- Lugoj" << endl
		 << "- Mehadia" << endl
		 << "- Drobeta" << endl
		 << "- Craiova" << endl
		 << "- Rimnicu Vilcea" << endl
		 << "- Fagaras" << endl
		 << "- Pitesti" << endl
		 << "- Bucharest" << endl
		 << "- Giurgiu" << endl
		 << "- Urziceni" << endl
		 << "- Hirsova" << endl
		 << "- Eforie" << endl
		 << "- Vaslui" << endl
		 << "- Iasi" << endl
		 << "- Neamt" << endl;
	cout << "Choose a city to start from: ";
	getline(cin, start);
	cout << "Choose a city to end at: ";
	getline(cin, end);
	cout << "- Uniform Cost Search" << endl
		 << "- Breath First Search" << endl
		 << "- Depth Limited Search" << endl
		 << "- Depth First Search" << endl
		 << "- Iterative Deepening Depth First Search" << endl
		 << "- Bidirectional Search" << endl
		 << "- Greedy Best First Search" << endl
		 << "- A* Search" << endl;
	cout << "Choose an algorithm: ";
	getline(cin, algorithm);

	vector<std::string> path;
	
	if (algorithm == "Uniform Cost Search")
		path = uniformCostSearch(start, end);
	else if (algorithm == "Breath First Search")
		path = breadthFirstSearch(start, end);
	else if (algorithm == "Depth Limited Search")
	{
		int limit;
		cout << "Choose a limit:" << endl;
		cin >> limit;

		path = depthLimitedSearch(start, end, limit);
	}
	else if (algorithm == "Depth First Search")
		path = depthFirstSearch(start, end);
	else if (algorithm == "Iterative Deepening Depth First Search")
		path = iterativeDeepeningDFS(start, end);
	else if (algorithm == "Bidirectional Search")
		path = bidirectionalSearch(start, end);
	else if (algorithm == "Greedy Best First Search")
		path = greedyBFS(start, end);
	else if (algorithm == "A* Search")
		path = AStarSearch(start, end);
	else
	{
		cout << "Invalid algorithm" << endl;
		cout << algorithm << endl;
		return 0;
	}

	cout << "Path from " << start << " to " << end << ":" << endl;
	printPath(path);

	return 0;
}

void printPath(vector<string> path)
{
	for (unsigned int i = 0; i < path.size(); i++)
	{
		if (i == path.size() - 1)
			cout << path[i];
		else
			cout << path[i] << " --> ";
	}
	cout << endl;
}