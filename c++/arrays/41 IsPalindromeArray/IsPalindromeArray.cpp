#include <iostream>
using namespace std;
void fillArray(int arr[], int &length)
{
    cout << "\nWhen You input a letter input process will stop\n";
    cout << "Enter The Element TO THe Array:\n";
    for (int i = 0; i < 100; i++)
    {
        if (!(cin >> arr[i]))
        {
            getchar(); // read the character input
            cin.clear(); // clear the fail flag
            cin.ignore(INT_MAX, '\n'); // ignore the remaining input buffer
            break;
        }
        length++;
    }
}

void PrintArray(int arr[] , int arrLength)
{
    for(int i = 0 ; i < arrLength ; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

bool IsPalindromeArray(int arr[], int length)
{
    for(int i = 0 ; i < length ; i++)
    {
        if(arr[i] != arr[length - i - 1])
            return false;
    }
    return true;
}

int main()
{
    int arr[100], arrLength = 0;
    fillArray(arr, arrLength);

    cout << "\nArray Elements:\n";
    PrintArray(arr, arrLength);

    if(IsPalindromeArray(arr, arrLength))
    {
        cout << "\nYes array is Palindrome\n";
    }
    else{
        cout << "\nNO array is NOT Palindrome\n"; 
    }
}