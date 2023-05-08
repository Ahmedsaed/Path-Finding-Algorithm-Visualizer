#include <iostream>
#include "rome.h"
#include "stack.h"

using namespace std;

int main(void)
{
	stack<int> stk;

	stk.push(5);
	stk.push(6);
	stk.push(7);
	stk.push(8);

	cout << stk.top() << endl;
	stk.pop();
	cout << stk.top() << endl;
	
	cout << "hallo world" << endl;
	cout << rome["Arad"][0].first << endl;
}
