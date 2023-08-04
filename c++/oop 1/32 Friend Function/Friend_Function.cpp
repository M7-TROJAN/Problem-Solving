// Friend Function

#include <iostream>
using namespace std;

class clsA
{
private:
    int Var1;

protected:
    int Var2;

public:
    int Var3;

    clsA()
    {
        Var1 = 10;
        Var2 = 20;
        Var3 = 30;
    }

    friend int MySum(clsA A1); // friend function
};

// this function is normal function and not a member of any class
int MySum(clsA A1)
{
    return A1.Var1 + A1.Var2 + A1.Var3;
}

int Fun2(clsA A1)
{
    // In this function, we are attempting to access the private member _Var1 and the protected member _Var3 of the clsA object A1.
    // However, we cannot access private and protected members of a class from outside the class, 
    // even though this function is a part of the same program.

    return A1.Var1 + A1.Var2 + A1.Var3; // error here
    // error: member "clsA::Var1" (declared at line 9) is inaccessible
    // error: member "clsA::Var2" (declared at line 12) is inaccessible
}

int main()
{
    clsA A1;

    cout << MySum(A1);

    system("pause > nul");

    return 0;
};
