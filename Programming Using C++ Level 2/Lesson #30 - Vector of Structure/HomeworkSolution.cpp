#include <vector>
#include <iostream>
using namespace std;
struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;
};
void ReadEmployees(vector<stEmployee> &vEmployees)
{
    char ReadMore = 'Y';
    stEmployee tempEmployee;
    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        cout << "Enter FirstName? ";
        cin >> tempEmployee.FirstName;

        cout << "Enter LastName? ";
        cin >> tempEmployee.LastName;

        cout << "Enter Salary? ";
        cin >> tempEmployee.Salary;

        vEmployees.push_back(tempEmployee);

        cout << "\nDo you want to read more employees? Y/N ?";
        cin >> ReadMore;
    }
}

void PrintEmployees(vector<stEmployee> &vEmployees)
{
    cout << "\nEmployees Vector: \n\n";
    for (stEmployee &Employee : vEmployees)
    {
        cout << "FirstName: " << Employee.FirstName << endl;
        cout << "LastName : " << Employee.LastName << endl;
        cout << "Salary : " << Employee.Salary << endl;
        cout << endl;
    }
    cout << endl;
}
int main()
{
    vector<stEmployee> vEmployees;
    ReadEmployees(vEmployees);
    PrintEmployees(vEmployees);
    return 0;
}