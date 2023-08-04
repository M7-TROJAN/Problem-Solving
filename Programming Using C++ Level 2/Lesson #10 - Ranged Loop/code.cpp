/*
    Ranged loop:
    Syntax:
        for ( rangeDeclaration : rangeExpression  )
        {
            code
        }
*/
#include <iostream>
using namespace std;
int main()
{
    int Array1[] = {1, 2, 3, 4};
    for (int &n : Array1)
    {
        cout << n << endl;
    }
    return 0;
}