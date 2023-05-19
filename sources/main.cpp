#include "main.h"
//#include "rome.h"
// #include "stack.h"
// #include "vector.h"
// #include "queue.h"
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
	
	cout << "hallo world" << endl;
	//cout << rome["Arad"][0].first << endl;

	vector<std::string> path = uniformCostSearch("Arad", "Bucharest");

	std::cout << "Shortest path from " << "Arad" << " to " << "Bucharest" << ":\n";
    for (const auto& city : path) {
        std::cout << city << " -> ";
    }
    std::cout << "\n";
}
