#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;  // Index for the last element in nums1
        int j = n - 1;  // Index for the last element in nums2
        int k = m + n - 1;  // Index for the last position in the merged array
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];  // Place the larger element from nums1 in the merged array
                i--;
            } else {
                nums1[k] = nums2[j];  // Place the larger element from nums2 in the merged array
                j--;
            }
            k--;
        }
        
        // Copy any remaining elements from nums2 to nums1 (if any)
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

// ..................................................................................


#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;  // Index for the last element in nums1
        int j = n - 1;  // Index for the last element in nums2
        int k = m + n - 1;  // Index for the last position in the merged array
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];  // Place the larger element from nums1 in the merged array
            } else {
                nums1[k--] = nums2[j--];  // Place the larger element from nums2 in the merged array
            }
        }
    }
};


/*

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

*/