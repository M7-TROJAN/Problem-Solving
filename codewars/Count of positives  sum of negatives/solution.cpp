#include <vector>
using namespace std;
vector<int> countPositivesSumNegatives(vector<int> input)
{
    if (input.empty())
        return input;
    vector<int> result(2, 0);
    for (int &num : input)
    {
        if (num > 0)
            result[0]++;
        else if (num < 0)
            result[1] += num;
    }
    return result;
}

// ..........................................................................

#include <vector>
using namespace std;
vector<int> countPositivesSumNegatives(vector<int> input)
{
    if (input.size() == 0)
        return {};
    int count = 0, sum = 0;
    for (int i = 0; i < input.size(); ++i)
        (input[i] > 0) ? ++count : sum += input[i];
    return {count, sum};
}