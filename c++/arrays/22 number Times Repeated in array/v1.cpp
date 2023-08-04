/* 
Write a program to read N elements and store them in array then print all array elements and ask for a number to check,
then print how many number a certain element repeated in that array.

Input:
5
Enter Array Elements:
Element[1] : 1
Element[2] : 1
Element[3] : 1
Element[4] : 2
Element[5] : 3
Enter the number you want to check: 1

Output:
Original array: 1 1 1 2 3
1 is repeated 3 time(s)
*/

#include <iostream>
using namespace std;
void ReadNumber(int &number)
{
    number = 0;
    do
    {
        // Read an integer value from the user
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
}

int main() {
    
    int n;
    cin >> n;
    int arr[n];

    cout << "Enter Array Elements:\n";
    for (short i = 0; i < n; i++)
    {
        cout << "Element[" << i+1 << "] : ";
        ReadNumber(arr[i]);
    }
    
    int checkNumber;
    int counter = 0;
    cout << "Enter The Number You Want To Check: ";
    ReadNumber(checkNumber);

    cout << "The Original Array Is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        if (arr[i] == checkNumber)
        {
            counter++;
        }
    }

    cout << checkNumber << " Is Repeated " << counter << " Time(s).";
    

}
