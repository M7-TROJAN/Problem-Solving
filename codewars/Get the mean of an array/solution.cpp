#include <vector>

int get_average(const std::vector<int> &marks)
{
    int marksSum = 0;
    int average = 0;

    for (const int &mark : marks)
    {
        marksSum += mark;
    }

    average = marksSum / marks.size();
    return average;
}

// ........................................................

#include <vector>
#include <numeric>

int get_average(std::vector<int> marks)
{
    return accumulate(marks.begin(), marks.end(), 0) / marks.size();
}