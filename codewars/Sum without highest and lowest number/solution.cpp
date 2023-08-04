#include <vector>
#include <algorithm>
using namespace std;

int sum(vector<int> numbers)
{
    if (numbers.size() < 2) return 0;
    std::sort(numbers.begin(), numbers.end());
    int sum = 0;

    for (int i = 1; i < numbers.size() - 1; i++)
        sum += numbers[i];

    return sum;
}

// ................................................................................................

#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int sum(vector<int> numbers)
{
    if (numbers.size()<=1)
        return 0;
    return accumulate(numbers.begin(),numbers.end(),0)-*max_element(numbers.begin(),numbers.end())-*min_element(numbers.begin(),numbers.end());
}