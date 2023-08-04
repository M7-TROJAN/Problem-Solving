#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> firstNumbers = {10, 30, 50, 70};
    vector<int> secondNumbers = {20, 40, 60, 80};

    vector<int>allNumbers(firstNumbers.size() + secondNumbers.size());

    merge(firstNumbers.begin(), firstNumbers.end(), secondNumbers.begin(), secondNumbers.end(), allNumbers.begin() );

    for(auto i : allNumbers)
        cout <<i << " ";
    cout << endl;
    return 0;
}

// Output Needed: 10 20 30 40 50 60 70 80