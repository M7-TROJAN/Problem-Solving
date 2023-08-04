#include <vector>
#include <algorithm>
using namespace std;
int sumOfDifferences(vector<int> arr)
{
    if (arr.size() <= 1)
        return 0;

    int result = 0;
    sort(arr.rbegin(), arr.rend());

    for (int i = 0; i < arr.size() - 1; i++)
        result += (arr.at(i) - arr.at(i + 1));
    return result;
}
// ............................................................................

// another way by using minmax_element();
#include <vector>
#include <algorithm>
using namespace std;
int sumOfDifferences(const std::vector<int> &arr)
{
    if (arr.empty())
        return 0;
    auto p = minmax_element(arr.cbegin(), arr.cend());
    return *p.second - *p.first;
}