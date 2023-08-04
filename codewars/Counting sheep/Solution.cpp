#include <vector>
using namespace std;
int count_sheep(vector<bool> arr)
{
    int result = 0;
    for (const bool &val : arr)
    {
        if (val)
            result++;
    }
    return result;
}
