#include<vector>
std::vector<int> divisible_by(std::vector<int> numbers, int divisor)
{
    std::vector<int> result;
    for (int &num : numbers)
    {
        if (num % divisor == 0)
            result.push_back(num);
    }
    return result;
}