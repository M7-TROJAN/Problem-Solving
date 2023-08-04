#include <vector>
std::vector<int> move_zeroes(const std::vector<int> &input)
{
    std::vector<int> result(input.size(), 0);
    int writeIndex = 0; // Index to write non-zero elements in result vector

    for (int num : input)
    {
        if (num != 0)
        {
            result[writeIndex] = num; // Write non-zero element to result vector at the writeIndex
            ++writeIndex; // Increment writeIndex to the next position
        }
    }

    return result;
}