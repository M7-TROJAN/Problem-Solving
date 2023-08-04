#include <iostream>
using namespace std;
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillArrayWithRandomNumbers(int arr[], int &length)
{
    cout << "\nEnter number of elements:\n";
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}
void PrintArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int evenCount(int arr[100], int arrLength)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 == 0)
        {
            Counter++;
        }
    }
    return Counter;
}
int main()
{
    int arr[100], length;
    srand((unsigned)time(NULL));
    FillArrayWithRandomNumbers(arr, length);
    cout << "\rArray Elements Is:\n";
    PrintArray(arr, length);
    cout << "\nEven Numbers count is: " << evenCount(arr, length) << endl;
}