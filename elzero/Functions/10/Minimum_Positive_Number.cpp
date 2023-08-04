#include <iostream>
using namespace std;

// Write Your Function Here
int minPositive(int arr[], int arrSize)
{
    int minPositiveNumber = INT16_MAX;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] < 1)
            continue;
        if (arr[i] < minPositiveNumber)
            minPositiveNumber = arr[i];
    }
    return minPositiveNumber;
}
int main()
{
    int numbers[] = {-10, -20, 15, 100, 10, 5, -50, 0}; // 5
    int numssize = size(numbers);
    cout << minPositive(numbers, numssize) << "\n";
    return 0;
}