#include <iostream>
using namespace std;

// Write Your Functions Here

float avg(int arr[], int arrSize)
{
    float result;
    for(short i = 0 ; i < arrSize ; i++)
    {
        result += arr[i];
    }
    return result / arrSize;
}
int main()
{
    int money[] = {10, 20, 15, 25, 30, 35};
    int monsize = size(money);
    cout << avg(money, monsize) << "\n"; // 22.5
    return 0;
}