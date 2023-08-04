#include <iostream>
using namespace std;
int main()
{
    int a = 10;

    cout << "a value = " << a << endl;
    cout << "a address = " << &a << endl;
    int *p;
    p = &a;

    cout << "Pointer Value = " << p;
    cout << endl;
    return 0;
}