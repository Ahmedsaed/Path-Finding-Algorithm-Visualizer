#include <bits/stdc++.h>
#include "../../include/romania.h"
#include "../../include/vector.h"
using namespace std;

int main()
{
    std::vector<int> built_in;
    udtl::vector<int> hand_made;
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
        built_in.push_back(test_cases[i]);
        hand_made.push_back(test_cases[i]);
    }

    built_in.pop_back();
    hand_made.pop_back();
    built_in.pop_back();
    hand_made.pop_back();

    if (hand_made.front() != built_in.front() || hand_made.back() != built_in.back())
    {
        rv = -1;
        cout << "front()/back() failed!!!!\n";
    }
    if (hand_made[0] != built_in[0])
    {
        rv = -1;
        cout << "[] operator failed!!!!\n";
    }
    if (hand_made.size() != built_in.size())
    {
        rv = -1;
        cout << "size() failed!!!!\n";
    }

    built_in.clear();
    hand_made.clear();

    if (hand_made.empty() != built_in.empty())
    {
        rv = -1;
        cout << "empty() failed!!!!\n";
    }

    return (rv);
}
