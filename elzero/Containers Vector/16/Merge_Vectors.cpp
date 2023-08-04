#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> n1 = {1, 2, 3};
    vector<int> n2 = {4, 5, 6};

    // Your Merge Code Here
    vector<int>allVectors(n1.size() + n2.size());
    merge(n1.begin(),n1.end(),n2.begin(),n2.end(),allVectors.begin());

    for (int i : allVectors)
    {
        cout << i << "\n";
    }
    return 0;
}

// Needed Output: 1 2 3 4 5 6