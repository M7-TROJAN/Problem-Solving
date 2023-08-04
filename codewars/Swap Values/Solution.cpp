#include <utility>

std::pair<int, int> swap_values(std::pair<int, int> values)
{
    int tempValue = values.first;
    values.first = values.second;
    values.second = tempValue;
    return values;
}



// another solution
#include <utility>

std::pair<int, int> swap_values(std::pair<int, int> values)
{
    std::swap(values.first, values.second);
    return values;
}