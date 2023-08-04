#include <iostream>
#include <vector>
using namespace std;

vector<int> range(int start, int end, int step = 1)
{
    vector<int> result;
    if (step > 0)
    {
        for (int i = start; i < end; i += step)
        {
            result.push_back(i);
        }
    }
    else if (step < 0)
    {
        for (int i = start; i > end; i += step)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    for (auto i : range(1, 10))
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : range(1, 10, 2))
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : range(10, 1, -2))
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
