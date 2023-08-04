#include <iostream>
#include <vector>
struct stEmployee
{
    std::string FirstName;
    std::string LastName;
    float Salary;
};
void addEmployeeToVector(std::vector<stEmployee>&);
void printVectorElements(std::vector<stEmployee>&);
float get_float(std::string);

int main()
{
    std::vector<stEmployee> vEmployees;
    addEmployeeToVector(vEmployees);
    printVectorElements(vEmployees);
}

void addEmployeeToVector(std::vector<stEmployee> & vEmployees)
{
    char addMore = 'y';
    stEmployee tempEmployee;
    do
    {
        std:: cout << "Enter Employee First Name: ";
        std:: cin  >> tempEmployee.FirstName;
        std:: cout << "Enter Employee Last Name: ";
        std:: cin  >> tempEmployee.LastName;
        tempEmployee.Salary = get_float("Enter Employee Salary: ");
        vEmployees.push_back(tempEmployee);

        std:: cout << "Do You Want To Add another One?: ";
        std:: cin  >> addMore;
    } while (addMore == 'y' || addMore == 'Y');
}

void printVectorElements(std::vector<stEmployee> & vEmployees)
{
    std::cout << "\nEmployees:\n\n";
    for (stEmployee &emp : vEmployees)
    {
        std:: cout << "First Name: " << emp.FirstName << std::endl;
        std:: cout << "Last Name : " << emp.LastName  << std::endl;
        std:: cout << "Salary    : " << emp.Salary    << std::endl;
        std:: cout << "========================\n";
    }
    std::cout << std::endl;
}

float get_float(std::string message = "")
{
    float number = 0;
    do
    {
        // Read a float value from the user
        std::cout << message;
        std::cin >> number;

        // Check if the input was invalid (i.e. not a number)
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            // cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }
        break;
    } while (true);
    return number;
}
