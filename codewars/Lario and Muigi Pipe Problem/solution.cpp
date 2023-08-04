#include <vector>
#include <algorithm>
using namespace std;
vector<int> pipe_fix(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int minVal = nums.front();
    int maxVal = nums.back();
    vector<int> result;

    for (int i = minVal; i <= maxVal; i++)
    {
        result.push_back(i);
    }
    return result;
}

// ........................................................................................

#include <vector>
#include <algorithm>
using namespace std;
vector<int> pipe_fix(const vector<int> &nums)
{
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    vector<int> result;
    for (int i = minVal; i <= maxVal; i++)
    {
        result.push_back(i);
    }
    return result;
}

// ........................................................................................

#include <algorithm>
#include <numeric>
using namespace std;

vector<int> pipe_fix(const vector<int>& nums) 
{  
    auto [min, max] = std::minmax_element(nums.begin(), nums.end());
    std::vector<int> result(*max - *min + 1);
    std::iota(result.begin(), result.end(), *min);
    return result;
}