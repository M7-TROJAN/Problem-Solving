#include <vector>

bool betterThanAverage(std::vector<int> classPoints, int yourPoints)
{
    int classPointsSum = yourPoints;
    for (int &point : classPoints)
    {
        classPointsSum += point;
    }
    return (classPointsSum / classPoints.size()) <= yourPoints;
}

// .....................................................................................

#include <vector>
#include <numeric>
using namespace std;

bool betterThanAverage(std::vector<int> classPoints, int yourPoints)
{
    return yourPoints >= accumulate(classPoints.begin(), classPoints.end(), 0.0) / classPoints.size();
}