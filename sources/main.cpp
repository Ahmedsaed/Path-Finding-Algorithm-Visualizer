#include "main.h"
#include "romania.h"
#include "algorithm.h"

using namespace std;

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
	
	// path = uniformCostSearch("Arad", "Bucharest");

	// std::cout << "Shortest path from " << "Arad" << " to " << "Bucharest" << ":\n";
    // for (const auto& city : path) {
    //     std::cout << city << " -> ";
    // }
    // std::cout << "\n";


	// path = depthLimitedSearch("Arad", "Bucharest", 5);

	// std::cout << "Shortest path from " << "Arad" << " to " << "Bucharest" << ":\n";
    // for (const auto& city : path) {
    //     std::cout << city << " -> ";
    // }
    // std::cout << "\n";

	// path = depthLimitedSearch("Arad", "Bucharest", 4);

	// std::cout << "Shortest path from " << "Arad" << " to " << "Bucharest" << ":\n";
    // for (const auto& city : path) {
    //     std::cout << city << " -> ";
    // }
    // std::cout << "\n";

	// path = depthFirstSearch("Arad", "Bucharest");

	// std::cout << "Shortest path from " << "Arad" << " to " << "Bucharest" << ":\n";
    // for (const auto& city : path) {
    //     std::cout << city << " -> ";
    // }
    // std::cout << "\n";

	// path = iterativeDeepeningDFS("Arad", "Bucharest");

	// std::cout << "Shortest path from " << "Arad" << " to " << "Bucharest" << ":\n";
    // for (const auto& city : path) {
    //     std::cout << city << " -> ";
    // }
    // std::cout << "\n";

	// path = breadthFirstSearch("Arad", "Bucharest");

	// std::cout << "Shortest path from " << "Arad" << " to " << "Bucharest" << ":\n";
    // for (const auto& city : path) {
    //     std::cout << city << " -> ";
    // }
    // std::cout << "\n";
	
	// path = bidirectionalSearch("Arad", "Bucharest");

	// std::cout << "Shortest path from " << "Arad" << " to " << "Bucharest" << ":\n";
    // for (const auto& city : path) {
    //     std::cout << city << " -> ";
    // }
    // std::cout << "\n";

	path = greedyBFS("Arad", "Bucharest");

	std::cout << "Shortest path from " << "Arad" << " to " << "Bucharest" << ":\n";
    for (const auto& city : path) {
        std::cout << city << " -> ";
    }
    std::cout << "\n";
}