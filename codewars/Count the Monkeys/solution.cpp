#include <vector>

std::vector<int> MonkeyCount(int n)
{
    std::vector<int> array;
    for (int i = 1; i <= n; i++)
    {
        array.push_back(i);
    }
    return array;
}