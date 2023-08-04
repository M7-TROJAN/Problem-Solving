/*
if we have unsorted array of 101 indexes containing the numbers from 1 to 100 and it has a repeating number.
How do I know this duplicate number?
*/

/*
to solve this problem we cane use One of the most efficient methods
"Floyd's Tortoise and Hare Algorithm" or "Cycle Detection Algorithm," which is based on the concept of linked list cycle detection.
*/


#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& arr) {
    // Step 1: Initialize slow and fast pointers
    int slow = arr[0];
    int fast = arr[0];

    // Step 2: Loop until slow and fast pointers meet
    do {
        slow = arr[slow];           // Move slow one step
        fast = arr[arr[fast]];      // Move fast two steps
    } while (slow != fast);

    //            3, 1, 4, 2, 5, 6, 9, 8, 7, 10, 4
    //slow = 9                      |
    //fast = 9                      |

    // Step 3: Reset fast to the beginning and keep slow at the meeting point
    fast = arr[0];

    // Step 4: Loop until slow and fast pointers meet again Move both pointers one step at a time
    while (slow != fast) {
        slow = arr[slow];           // Move slow one step
        fast = arr[fast];           // Move fast one step
    }
    //            3, 1, 4, 2, 5, 6, 9, 8, 7, 10, 4
    //slow = 4                                   |
    //fast = 4          |
    // so 4 is the duplicate number

    // Step 5: The meeting point is the duplicate number
    return slow;
}

int main() {
    vector<int> arr = {3, 1, 4, 2, 5, 6, 9, 8, 7, 10, 4}; // Example array (with duplicate 4)
    
    int duplicate_number = findDuplicate(arr);
    cout << "The duplicate number is: " << duplicate_number << endl; // 4

    return 0;
}

/*
algorithm steps:

1- Initialize two pointers, slow and fast, both pointing to the first element of the array.

2- Use the slow pointer to move one step at a time and the fast pointer to move two steps at a time. Continue until they meet inside the loop.

3- Once the two pointers meet, reset the fast pointer to the first element of the array and keep the slow  at the meeting point.

4- Move both pointers one step at a time until they meet again. The point where they meet will be the duplicate number.

5- The meeting point is the duplicate number return one of them.
*/

/*
The algorithm that used in the code is called (Floyd's Tortoise and Hare Algorithm) or (Cycle Detection Algorithm.) by Robert W. Floyd 

This algorithm has a time complexity of O(n) and a space complexity of O(1),
making it an efficient way to find the duplicate number in an unsorted array.
*/