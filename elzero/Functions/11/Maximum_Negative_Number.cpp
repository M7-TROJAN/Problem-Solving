#include <iostream>
using namespace std;

// Write Your Function Here
int maxNegative(int arr[], int arrSize)
{
    int maxNegativeNumber = INT8_MIN;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] >= 0)
            continue;
        if (arr[i] > maxNegativeNumber)
            maxNegativeNumber = arr[i];
    }
    return maxNegativeNumber;
}
int main()
{
    int numbers[] = {-10, -20, 15, 100, 10, 5, -50, 0, -5, -10}; 
    int numssize = size(numbers);
    cout << maxNegative(numbers, numssize) << "\n"; // -5
    return 0;
}