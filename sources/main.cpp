#include "main.h"
#include "romania.h"
#include "algorithm.h"

using namespace std;

void printPath(vector<string> path);

int main(void)
{
	// cout << "Vector" << endl;
	// vector <int> vec;
	// vec.push_back(6);
	// cout<<vec.size()<<" "<<vec.empty()<<'\n';
	// cout<<vec[0]<<'\n';
	// vec.pop_back();

	// cout << "Queue" << endl;
	// queue<int> qu;
	// qu.push(1);
	// qu.push(5);

	// cout << qu.front() << endl;
	// qu.pop();
	// cout << qu.front() << " " << qu.size() << endl;

	// cout << "Stack" << endl;
	// stack<int> stk;
	// stk.push(5);
	// stk.push(6);
	// stk.push(7);
	// stk.push(8);

	// cout << stk.top() << endl;
	// stk.pop();
	// cout << stk.top() << endl;
	
	// cout << "hallo world" << endl;
	//cout << romania["Arad"][0].first << endl;

	vector<std::string> path;
	
	cout << "Uniform Cost Search" << endl;
	path = uniformCostSearch("Arad", "Bucharest");

	std::cout << "Path from " << "Arad" << " to " << "Bucharest" << ":\n";
    printPath(path);

	cout << "Depth Limited Search with limit 5" << endl;
	path = depthLimitedSearch("Arad", "Bucharest", 5);

	std::cout << "Path from " << "Arad" << " to " << "Bucharest" << ":\n";
    printPath(path);

	cout << "Depth Limited Search with limit 4" << endl;
	path = depthLimitedSearch("Arad", "Bucharest", 4);

	std::cout << "Path from " << "Arad" << " to " << "Bucharest" << ":\n";
    printPath(path);

	cout << "Depth First Search" << endl;
	path = depthFirstSearch("Arad", "Bucharest");

	std::cout << "Path from " << "Arad" << " to " << "Bucharest" << ":\n";
    printPath(path);

	cout << "Iterative Deepening Depth First Search" << endl;
	path = iterativeDeepeningDFS("Arad", "Bucharest");

	std::cout << "Path from " << "Arad" << " to " << "Bucharest" << ":\n";
    printPath(path);

	cout << "Breadth First Search" << endl;
	path = breadthFirstSearch("Arad", "Bucharest");

	std::cout << "Path from " << "Arad" << " to " << "Bucharest" << ":\n";
    printPath(path);
	
	cout << "Bidirectional Search" << endl;
	path = bidirectionalSearch("Arad", "Bucharest");

	std::cout << "Path from " << "Arad" << " to " << "Bucharest" << ":\n";
    printPath(path);

	cout << "Greedy Best First Search" << endl;
	path = greedyBFS("Arad", "Bucharest");

	std::cout << "Path from " << "Arad" << " to " << "Bucharest" << ":\n";
    printPath(path);

	cout << "A* Search" << endl;
	path = AStarSearch("Arad", "Bucharest");

	std::cout << "Path from " << "Arad" << " to " << "Bucharest" << ":\n";
    printPath(path);
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
	cout << endl << endl;
}