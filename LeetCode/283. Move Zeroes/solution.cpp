#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zerosCount = 0;  // Variable to keep track of the number of zeroes encountered
        auto it = nums.begin();  // Iterator to iterate over the vector

        while (it != nums.end()) {
            if (*it == 0) {
                it = nums.erase(it);  // Erase the zero element and update the iterator to the next element ( The erase function returns an iterator pointing to the element immediately following the erased element)
                zerosCount++;  // Increment the count of zeroes
            } else {
                ++it;  // Move to the next element
            }
        }

        for (int i = 0; i < zerosCount; i++) {
            nums.push_back(0);  // Add zeroes at the end of the vector
        }
    }
};


// ............................................................................................................


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0;  // Index to keep track of the next position for non-zero elements

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZeroIndex++] = nums[i];  // Move non-zero element to the next position
            }
        }

        while (nonZeroIndex < nums.size()) {
            nums[nonZeroIndex++] = 0;  // Fill remaining positions with zeroes
        }
    }
};



/*

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

*/