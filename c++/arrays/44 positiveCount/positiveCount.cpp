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
        arr[i] = RandomNumber(-100, 100);
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
int positiveCount(int arr[100], int arrLength)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] >= 0) // Zero Is Not positive Or Negative Number But We Will Assume it's a positive
        {
            Counter++;
        }
    }
    return Counter;
}
int main()
{
    int arr[100], length;
    srand(time(NULL));
    FillArrayWithRandomNumbers(arr, length);
    cout << "\rArray Elements Is:\n";
    PrintArray(arr, length);
    cout << "\npositive Numbers count is: " << positiveCount(arr, length) << endl;
}
