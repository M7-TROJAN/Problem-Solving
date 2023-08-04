#include <vector>
#include <algorithm>

std::vector<int> flip(const char dir, const std::vector<int> &arr)
{
    std::vector<int> result = arr;
    if( dir == 'R') std::sort(result.begin(), result.end());
    if( dir == 'L') std::sort(result.rbegin(), result.rend());
    return result;
}
