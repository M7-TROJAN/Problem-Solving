// Objects with Parameterized Constructor and Array

#include <iostream>
#include <vector>
using namespace std;
class clsA
{
public:
    // Parameterized Constructor
    clsA(int value)
    {
        x = value;
    }
    int x;
    void Print()
    {
        cout << "The value of x=" << x << endl;
    }
};
int main()
{

    // Initializing 3 array Objects with function calls of
    // parameterized constructor as elements of that array
    clsA obj[] = {clsA(10), clsA(20), clsA(30)};
    // using print method for each of three elements.
    for (int i = 0; i < 3; i++)
    {
        obj[i].Print();
    }
    return 0;

    system("pause > nul");
}