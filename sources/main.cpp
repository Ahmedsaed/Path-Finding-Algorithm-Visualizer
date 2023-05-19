#include <iostream>
//#include "rome.h"
#include "stack.h"
#include "vector.h"

using namespace std;

int main(void)
{
	vector <int> vec;
	vec.push_back(6);
	cout<<vec.size()<<" "<<vec.empty()<<'\n';
	cout<<vec[0]<<'\n';
	vec.pop_back();
	

	// stk.push(5);
	// stk.push(6);
	// stk.push(7);
	// stk.push(8);

	// cout << stk.top() << endl;
	// stk.pop();
	// cout << stk.top() << endl;
	
	cout << "hallo world" << endl;
	//cout << rome["Arad"][0].first << endl;
}
