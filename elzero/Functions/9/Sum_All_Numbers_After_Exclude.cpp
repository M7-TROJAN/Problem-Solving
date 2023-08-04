#include <iostream>
using namespace std;

int sumall(int arr[], int arrSize, int avoid)
{
    int res = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == avoid)
            continue;
        res += arr[i];
    }
    return res;
}
int main()
{
    int numbers[] = {13, 20, 3, 30, 5, 7, 40, 13}; // 105
    int numssize = size(numbers);
    int noneed = 13;
    cout << sumall(numbers, numssize, noneed) << "\n";
    return 0;
}