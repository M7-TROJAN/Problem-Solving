
#include <iostream>
using namespace std;

// function that performs binary search and returns index of target if found, else returns -1
int bainrySearch(int num[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // calculate middle index
        if (num[mid] == target)              // if target found at mid index, return mid index
            return mid;
        else if (num[mid] < target) // if target is greater than middle element, search in right half of array
        {
            left = mid + 1;                         // update left to mid+1
            bainrySearch(num, left, right, target); // recursively call binarySearch with updated left index
        }
        else // if target is smaller than middle element, search in left half of array
        {
            right = mid - 1;                        // update right to mid-1
            bainrySearch(num, left, right, target); // recursively call binarySearch with updated right index
        }
    }
    return -1; // if target not found, return -1
}

int main()
{
    int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};     // array of numbers to search in
    int n = size(num);                               // get size of array
    int target;                                      // target number to search for
    cin >> target;                                   // get input from user for target number
    int index = bainrySearch(num, 0, n - 1, target); // perform binary search on array, with left index = 0, right index = n-1
    if (index < 0)                                   // if target not found in array
        cout << target << " Is Not Found\n";
    else // if target found in array
        cout << target << " Is Found In Index Number " << index << endl;
}
