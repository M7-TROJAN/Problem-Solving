#include <vector>
using namespace std;
vector<int> reverseSeq(int n)
{
    vector<int> nums;
    for (int i = n; i >= 1; i--)
    {
        nums.push_back(i);
    }
    return nums;
}

// .........................................
// another smart solution

#include <vector>
using namespace std;
vector<int> reverseSeq(int n)
{
    vector<int> v;
    while (n)
        v.push_back(n--);
    return v;
}