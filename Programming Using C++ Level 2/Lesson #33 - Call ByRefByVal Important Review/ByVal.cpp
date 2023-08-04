#include <iostream>
using namespace std;
void Func(int x)
{
    x++;
}
int main()
{
    int a = 10;
    cout << "\n Variable (a) Befor calling function = " << a << endl;
    Func(a);
    cout << "\n Variable (a) after calling function = " << a << endl;
    return 0;
}