/*
Problem:
Write a program to fill array with max size 100 with random numbers from 1 to 100,
copy it to another array in reverse order and print it
*/

#include <iostream>
using namespace std;
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[arrLength - 1 - i];
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];
    CopyArrayInReverseOrder(arr, arr2, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arrLength);
    return 0;
}