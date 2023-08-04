#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;  // Variable to store the maximum profit
        int minPrice = prices[0];  // Variable to store the minimum price encountered
        
        for (int i = 1; i < prices.size(); i++) 
        {
            if (prices[i] < minPrice) 
                minPrice = prices[i];  // Update the minimum price if a lower price is found
            else 
            {
                int currentProfit = prices[i] - minPrice;  // Calculate the profit if selling at the current price
                maxProfit = max(maxProfit, currentProfit);  // Update the maximum profit if the current profit is greater
            }
        }
        
        return maxProfit;  // Return the maximum profit
    }
};



/*

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

*/