//  solution by using language fundamentals
double calcAverage(const std::vector<int> &values)
{
    if (values.empty())
        return 0;
    double valuesSum = 0;
    for (int i = 0; i < values.size(); i++)
        valuesSum += values.at(i);
    return valuesSum / values.size();
}

// ...............................................................................

// another solution by using accumulate() function from numeric header file
#include <vector>
#include <numeric>
double calcAverage(const std::vector<int> &values)
{
    return accumulate(values.begin(), values.end(), 0.0) / values.size();
}