
// Objects and Dynamic Array

#include <iostream>
#include <vector>
using namespace std;
class clsA
{
public:
    // dummy constructor
    clsA() {}
    // Parameterized Constructor
    clsA(int value)
    {
        this->x = value;
    }
    int x;
    void Print()
    {
        cout << "The value of x=" << x << endl;
    }
};

int main()
{
    short NumberOfObjects = 5;
    // allocating dynamic array
    // of Size NumberOfObjects using new keyword
    clsA *arrA = new clsA[NumberOfObjects];
    // calling constructor
    // for each index of array
    for (int i = 0; i < NumberOfObjects; i++)
    {
        arrA[i] = clsA(i);
    }
    // printing contents of array
    for (int i = 0; i < NumberOfObjects; i++)
    {
        arrA[i].Print();
    }
    return 0;

    system("pause > nul");
}