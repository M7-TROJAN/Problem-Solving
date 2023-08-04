#include <vector>
int grow(std::vector<int> nums) {
    int res = 1;
    for (auto &&i : nums)
    {
        res*=i;
    }
    return res;
}