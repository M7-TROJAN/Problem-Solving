#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {5, 4, 3, 2, 1};

    // Method One
    // reverse(nums.begin(), nums.end());

    // Method Two
    // sort(nums.begin(), nums.end());

    // Method Three -> Use Swap + Loop For Challenge
    bool swapped;
    int count = nums.size();
    do
    {
        swapped = false;
        for (int i = 0; i < count-1; i++)
        {
            if(nums.at(i) > nums.at(i+1))
            {
                int temp = nums.at(i);
                nums.at(i) = nums.at(i+1);
                nums.at(i+1) = temp;
                swapped = true;
                // or we can use swap fun => swap(nums.at(i), nums.at(i+1));
            }
        }
        count--;
        
    } while (swapped);
    

    for (int i : nums)
    {
        cout << i << "\n";
    }

    return 0;
}

// Needed Output 1 2 3 4 5