#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int &x = a;

    cout << sizeof(a) << endl; // 4
    cout << sizeof(x) << endl; // 4

    cout << &a << endl; // Hexadecimal Number
    cout << &x << endl; // the same above Hexadecimal Number

    cout << a << endl; // value of a => 10
    cout << x << endl; // value of x => 10

    x = 20;
    cout << a << endl; // value of a => 20
    cout << x << endl; // value of x => 20

    a = 30;
    cout << a << endl; // value of a => 30
    cout << x << endl; // value of x => 30
}