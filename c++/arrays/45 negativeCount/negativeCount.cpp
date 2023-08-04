#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillArrayWithRandomNumbers(int *&arr, int &length)
{
    cout << "\nEnter number of elements:\n";
    cin >> length;
    // allocate memory to array
    arr = new int[length];
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
int negativeCount(int arr[100], int arrLength)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < 0) // Zero Is Not positive Or Negative Number But We Will Assume it's a positive
        {
            Counter++;
        }
    }
    return Counter;
}

int main()
{
    int *arr, length;
    srand(time(NULL));
    FillArrayWithRandomNumbers(arr, length);
    cout << "\rArray Elements Is:\n";
    PrintArray(arr, length);
    cout << "\nnegative Numbers count is: " << negativeCount(arr, length) << endl;

    // deallocate memory using delete statement
    delete[] arr;
    // make the array doesn't pointing any thing
    arr = NULL;
}