// Friend Classes

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
    // This will grant access for everything to class B
    friend class clsB; // friend class
};
class clsB
{
public:
    void display(clsA &A1)
    {
        cout << "The value of Var1=" << A1.Var1 << endl;
        cout << "The value of Var2=" << A1.Var2 << endl;
        cout << "The value of Var3=" << A1.Var3 << endl;
    }
};

int main()
{
    clsA A1;
    clsB B1;
    B1.display(A1);

    system("pause > nul");
    return 0;
};