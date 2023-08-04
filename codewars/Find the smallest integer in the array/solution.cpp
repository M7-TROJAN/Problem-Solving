#include <vector>
#include <algorithm>
using namespace std;
int findSmallest(vector<int> list)
{
    return *min_element(list.begin(), list.end());
}

// ...................................................................

#include <vector>
using namespace std;
int findSmallest(vector<int> list)
{
    int min = list.front();
    for (auto i : list)
    {
        if (i < min)
            min = i;
    }
    return min;
}

// ...................................................................

#include <vector>
#include <algorithm>
using namespace std;
int findSmallest(vector<int> list)
{
    sort(list.begin(), list.end());
    return list[0];
}
