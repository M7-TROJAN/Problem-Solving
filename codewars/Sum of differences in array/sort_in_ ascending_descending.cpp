#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {10, 500, 60, -20, 20, 20, 100, 20};

    // print vector elements befor sorting
    for (int &n : nums)
    {
        cout << n << "\n";
    }
    cout << "=====================\n";

    // sort vector elements in ascending order
    sort(nums.begin(), nums.end());

    // print vector elements after sorting in ascending order
    for (int &n : nums)
    {
        cout << n << "\n";
    }
    cout << "=====================\n";

    // sort vector elements in descending order
    sort(nums.rbegin(), nums.rend());

    // print vector elements after sorting in descending order
    for (int &n : nums)
    {
        cout << n << "\n";
    }
    cout << "=====================\n";

    return 0;
}



/*
sort(nums.begin(), nums.end());
sort(nums.rbegin(), nums.rend());
The difference between the two statements is in the order of sorting and the direction of sorting.

1- sort(nums.begin(), nums.end());: This statement sorts the elements in ascending order using the std::sort function.
It rearranges the elements of the nums container in such a way that they are in non-decreasing order.
In other words, the smallest element will be at the beginning (nums.begin()) and the largest element will be at the end (nums.end()).

2- sort(nums.rbegin(), nums.rend());: This statement sorts the elements in descending order using the std::sort function in conjunction with reverse iterators.
It rearranges the elements of the nums container in reverse order, so the largest element will be at the beginning (nums.rbegin())
and the smallest element will be at the end (nums.rend()). Essentially, it sorts the elements in a non-increasing order.

To summarize, the first statement sorts the elements in ascending order, while the second statement sorts the elements in descending order.
*/