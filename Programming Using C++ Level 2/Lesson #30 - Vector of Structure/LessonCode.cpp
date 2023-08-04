#include <vector>
#include <iostream>
using namespace std;
struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;
};
int main()
{
    vector<stEmployee> vEmployees;
    stEmployee tempEmployee;

    tempEmployee.FirstName = "Mahmoud";
    tempEmployee.LastName = "Mattar";
    tempEmployee.Salary = 5000;
    vEmployees.push_back(tempEmployee);

    tempEmployee.FirstName = "Ali";
    tempEmployee.LastName = "Mohamed";
    tempEmployee.Salary = 300;
    vEmployees.push_back(tempEmployee);

    tempEmployee.FirstName = "Rahma";
    tempEmployee.LastName = "Yasser";
    tempEmployee.Salary = 1000;
    vEmployees.push_back(tempEmployee);

    cout << "Employees Vector:\n";
    for (stEmployee &Employee : vEmployees)
    {
        cout << "FirstName: " << Employee.FirstName << endl;
        cout << "LastName : " << Employee.LastName  << endl;
        cout << "Salary   : " << Employee.Salary    << endl;
        cout << endl;
    }
    cout << endl;
    return 0;
}