#include <vector>

int square_sum(const std::vector<int>& numbers)
{
    int result = 0;
    for(int number : numbers)
    {
      result += (number * number);
    }
    return result;
}