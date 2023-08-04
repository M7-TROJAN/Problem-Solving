#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};

    // Your Code Here
    int middle = nums.size()/2;
    rotate(nums.begin(), nums.begin() + middle, nums.end());

    for (int i : nums)
    {
        cout << i << "\n";
    }
    return 0;
}

// Needed Output: 5 6 7 8 1 2 3 4