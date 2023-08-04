#include <iostream>
using namespace std;
int ReadNumber()
{
    int number = 0;
    do
    {
        // Read an integer value from the user
        cout << "\nPlease enter a number? ";
        cin >> number;

        // Check if the input was invalid (i.e. not an integer)
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a valid integer." << endl;
            continue;
        }
        break;
    } while (true);
    return number;
}
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    // its a new element so we need to add the length by 1
    arrLength++;
    arr[arrLength - 1] = Number;
}
void InputUserNumbersInArray(int arr[100], int &arrLength)
{
    bool AddMore = true;
    do
    {
        AddArrayElement(ReadNumber(), arr, arrLength);
        cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";

        cin >> AddMore;
    } while (AddMore);
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[100], arrLength = 0;
    InputUserNumbersInArray(arr, arrLength);
    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array elements: ";
    PrintArray(arr, arrLength);
    return 0;
}