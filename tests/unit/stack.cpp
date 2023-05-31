#include <bits/stdc++.h>
#include "../../include/romania.h"
#include "../../include/stack.h"
using namespace std;

int main()
{
    std::stack<int> built_in;
    udtl::stack<int> hand_made;
    int rv = 0;
    int test_cases[6] = {
        7,
        4,
        200,
        1,
        10000,
        135315135
    };

    for (int i = 0; i < 6; i++)
    {
        built_in.push(test_cases[i]);
        hand_made.push(test_cases[i]);
    }

    built_in.pop();
    hand_made.pop();
    built_in.pop();
    hand_made.pop();

    if (hand_made.top() != built_in.top())
    {
        rv = -1;
        cout << "Front() of queue failed!!!!\n";
    }
    if (hand_made.empty() != built_in.empty())
    {
        rv = -1;
        cout << "Empty() of queue failed!!!!\n";
    }

    return (rv);
}
