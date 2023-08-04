#include <vector>
using namespace std;
vector<int> countBy(int x, int n)
{
    if(x == 0 || n == 0) return {};
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        result.push_back(x * i);
    }
    return result;
}