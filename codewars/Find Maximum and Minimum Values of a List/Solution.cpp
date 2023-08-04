#include <vector>
using namespace std;

int min(vector<int> list)
{
    int minValue = list.at(0);
    for (int i : list)
    {
        if (minValue > i)
            minValue = i;
    }
    return minValue;
}

int max(vector<int> list)
{
    int maxValue = list[0];
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] > maxValue)
            maxValue = list[i];
    }
    return maxValue;
}
