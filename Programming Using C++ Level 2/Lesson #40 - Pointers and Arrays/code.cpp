#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {10, 20, 30, 40};
    int *ptr;
    ptr = arr;

    // ptr is equivalent to &arr[0];                  (is equivalent to) means => يُعادل
    // ptr + 1 is equivalent to &arr[1];
    // ptr + 2 is equivalent to &arr[2];
    // ptr + 3 is equivalent to &arr[3];

    cout << "\nAddresses By access with arr are:\n";
    cout << arr     << endl;
    cout << arr + 1 << endl;
    cout << arr + 2 << endl;
    cout << arr + 3 << endl;
    cout << "\nAddresses By access with ptr are:\n";
    cout << ptr     << endl;
    cout << ptr + 1 << endl;
    cout << ptr + 2 << endl;
    cout << ptr + 3 << endl;

    cout << "\nValues By access with arr are: \n";
    cout << *(arr)     << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr + 2) << endl;
    cout << *(arr + 3) << endl;
    cout << "\nValues are By access with ptr: \n";
    cout << *(ptr)     << endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr + 2) << endl;
    cout << *(ptr + 3) << endl;

    return 0;
}