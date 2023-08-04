
/*
two methods to merge two vectors
AB.reserve( A.size() + B.size() ); // preallocate memory

AB.insert( AB.end(), A.begin(), A.end() );
AB.insert( AB.end(), B.begin(), B.end() );
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> n1 = {1, 2, 3};
    vector<int> n2 = {4, 5, 6};

    // Your Insert Code Here
    vector<int> allVectors;
    allVectors.insert(allVectors.begin(), n1.begin(),n1.end());
    allVectors.insert(allVectors.end(), n2.begin(),n2.end());

    for (int i : allVectors)
    {
        cout << i << "\n";
    }

    return 0;
}
