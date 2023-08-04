#include <iostream>
using namespace std;
struct stEmployee
{
    string Name;
    float Salary;
};
int main()
{
    stEmployee Employee1;
    Employee1.Name = "Mohammed Mattar";
    Employee1.Salary = 5000;

    cout << Employee1.Name << endl;
    cout << Employee1.Salary << endl;

    stEmployee * ptr = NULL;
    ptr = &Employee1;
    cout << "\nUsing Pointer:\n";
    cout << ptr->Name << endl;
    cout << ptr->Salary << endl;
    return 0;
}