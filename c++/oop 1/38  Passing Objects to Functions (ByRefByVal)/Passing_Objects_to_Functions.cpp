
// Passing Object to Functions (ByRef/ByVal)
// Objects can be treated like any data type such as int, bool, string ...etc,
// They can be passed to functions as parameters either by reference or by value.

#include <iostream>
using namespace std;

class clsA
{
public:
    int x;

    void Print()
    {
        cout << "The value of x=" << x << endl;
    }
};

// Object sent by value, any updates will not be reflected on the original object
void Fun1(clsA A1)
{
    A1.x = 100; // This will not affect the original object since it's passed by value
}

// Object sent by reference, any updates will be reflected on the original object
void Fun2(clsA &A1)
{
    A1.x = 200; // This will affect the original object since it's passed by reference
}

int main()
{
    clsA A1;
    A1.x = 50;
    cout << "A.x before calling function1: " << endl;
    A1.Print();

    // Pass by value, object will not be affected.
    Fun1(A1);

    cout << "\nA.x after calling function1 (by value): " << endl;
    A1.Print(); // The value of A.x will still be 50, not 100

    // Pass by reference, object will be affected.
    Fun2(A1);

    cout << "\nA.x after calling function2 (by reference): " << endl;
    A1.Print(); // The value of A.x will be updated to 200

    system("pause > nul");
    return 0;
}
