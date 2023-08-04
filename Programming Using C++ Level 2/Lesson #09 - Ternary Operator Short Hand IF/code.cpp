/*
    Ternary Operator (short If)
    Syntax:
        Condition ? Expresion 1 (if true) : Expresion 2 (if false);
*/

#include <iostream>
using namespace std;
int main()
{
    int Number = 0;
    cin >> Number;
    string Result;
    Result = (Number == 0) ? "Zero" : ((Number > 0) ? "Positive" : "Negative");
    cout << "Number is " << Result;
    return 0;
}

/*
int main()
{
    int Number = 0;
    cin >> Number;
    (Number == 0) ? cout << "Zero" : ((Number > 0) ? cout << "Positive" : cout << "Negative");
    return 0;
}
*/