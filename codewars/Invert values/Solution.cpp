// Given a set of numbers, return the additive inverse of each. Each positive becomes negatives, and the negatives become positives.

#include <vector>
std::vector<int> invert(std::vector<int> values)
{
    //  multiplying any number by -1 will give you its additive inverse
    // the additive inverse of x is -x and additive inverse of -x is x
    for (int i = 0; i < values.size(); i++)
    {
        values.at(i)*= -1;
    }
    return values;
}
