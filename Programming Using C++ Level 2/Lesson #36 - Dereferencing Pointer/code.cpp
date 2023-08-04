#include <iostream>
using namespace std;
int main()
{
    int a = 10;

    cout << "a value = " << a << endl;
    cout << "a address = " << &a << endl;
    int *p;
    p = &a;

    cout << "Pointer Value = " << p << endl;
    cout << "Value of the address that p is pointing to is " << *p << endl;
    *p = 20;
    cout << a << endl;
    cout << *p << endl;
    a = 30;
    cout << a << endl;
    cout << *p << endl;

    cout << endl;
    return 0;
}