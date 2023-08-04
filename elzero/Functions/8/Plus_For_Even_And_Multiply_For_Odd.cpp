#include <iostream>
using namespace std;
int plusAndMultiply(int arr[], int arrSize)
{
    int plus = 0, multiply = 1;
    for(short i= 0 ; i < arrSize ; i++)
    {
        if(arr[i]%2 == 0)
            plus += arr[i];
        else
            multiply *= arr[i];
    }
    return plus + multiply;
}
int main()
{
    int numbers[] = {10, 20, 3, 30, 5, 7, 40};
    int numsSize = size(numbers);
    cout << plusAndMultiply(numbers, numsSize) << "\n"; // 205
    return 0;
}