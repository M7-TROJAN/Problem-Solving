//   Multi Level Inheritance    means ->  الوراثة متعددة المستويات

#include <iostream>
using namespace std;
class clsPerson
{
private:
    int _ID;           // Private member variable to store the person's ID
    string _FirstName; // Private member variable to store the person's first name
    string _LastName;  // Private member variable to store the person's last name
    string _Email;     // Private member variable to store the person's email
    string _Phone;     // Private member variable to store the person's phone number

public:
    // default Constructor
    // we put the default constructor here temporarily because inheritance will use it,
    // in the coming lectures, we will solve the parameterized constructor with inheritance.
    clsPerson() {}

    // Constructor to initialize the Person object with provided information
    clsPerson(int id, string firstName, string lastName, string email, string phone)
    {
        _ID = id;
        _FirstName = firstName;
        _LastName = lastName;
        _Email = email;
        _Phone = phone;
    }

    // Setter and Getter methods for modifying and accessing the first name
    void SetFirstName(string fName)
    {
        _FirstName = fName;
    }
    string GetFirstName()
    {
        return _FirstName;
    }

    // Setter and Getter methods for modifying and accessing the last name
    void SetLastName(string lName)
    {
        _LastName = lName;
    }
    string GetLastName()
    {
        return _LastName;
    }

    // Setter and Getter methods for modifying and accessing the email
    void SetEmail(string email)
    {
        _Email = email;
    }
    string GetEmail()
    {
        return _Email;
    }

    // Method to get the full name of the person by concatenating first and last name
    string GetFullName()
    {
        return _FirstName + " " + _LastName;
    }

    // Getter method to access the person's ID (Read Only Property)
    int GetID()
    {
        return _ID;
    }

    // Setter and Getter methods for modifying and accessing the phone number
    void SetPhone(string phone)
    {
        _Phone = phone;
    }
    string GetPhone()
    {
        return _Phone;
    }

    // Method to print the person's information
    void printInfo()
    {
        cout << "Info:\n";
        cout << "==================\n";
        cout << "ID: " << _ID << endl;
        cout << "FirstName: " << _FirstName << endl;
        cout << "LastName: " << _LastName << endl;
        cout << "FullName: " << GetFullName() << endl;
        cout << "Email: " << _Email << endl;
        cout << "Phone: " << _Phone << endl;
        cout << "==================\n";
    }

    // Method to send an email message
    void SendEmail(string Subject, string Body)
    {
        cout << "The Following Message Sent Successfully To Email: " << _Email << endl;
        cout << "Subject: " << Subject << "\n";
        cout << "Body: " << Body << endl;
    }

    // Method to send an SMS message
    void SendSMS(string TextMessage)
    {
        cout << "The Following SMS Sent Successfully To Phone: " << _Phone << endl;
        cout << TextMessage << "\n";
    }
};

class clsEmployee : public clsPerson
{
private:
    double _Salary;
    string _Department;
    string _Title;

public:
    // Constructor for clsEmployee class
    // The constructor takes all the parameters for the clsPerson class (id, fName, lName, email, phone),
    // and additional parameters for the clsEmployee class (title, department, salary).
    // The constructor uses the member initializer list to initialize the base class (clsPerson) and derived class (clsEmployee) members.
    clsEmployee(int id, string fName, string lName, string email, string phone, string title, string department, double salary)
        : clsPerson(id, fName, lName, email, phone), // Call the base class constructor (clsPerson) with provided parameters.
          _Salary(std::move(salary)),               // Move the value of 'salary' to '_Salary' member.
          _Department(std::move(department)),       // Move the value of 'department' to '_Department' member.
          _Title(std::move(title))                  // Move the value of 'title' to '_Title' member.
    {
        // The body of the constructor is empty, as all member variables are already initialized in the member initializer list.
    }

    // Setter and Getter methods for modifying and accessing the salary
    void SetSalary(double salary)
    {
        _Salary = salary;
    }
    double GetSalary()
    {
        return _Salary;
    }

    // Setter and Getter methods for modifying and accessing the Department
    void SetDepartment(string department)
    {
        _Department = department;
    }
    string GetDepartment()
    {
        return _Department;
    }

    // Setter and Getter methods for modifying and accessing the title
    void SetTitle(string title)
    {
        _Title = title;
    }
    string GetTitle()
    {
        return _Title;
    }

    // Method to print the Employee's information
    // Override function
    void printInfo()
    {
        cout << "Info:\n";
        cout << "==================\n";
        cout << "ID        : " << GetID() << endl;
        cout << "FirstName : " << GetFirstName() << endl;
        cout << "LastName  : " << GetLastName() << endl;
        cout << "FullName  : " << GetFullName() << endl;
        cout << "Title     : " << GetTitle() << endl;
        cout << "Email     : " << GetEmail() << endl;
        cout << "Phone     : " << GetPhone() << endl;
        cout << "Department: " << GetDepartment() << endl;
        cout << "Salary    : " << GetSalary() << endl;
        cout << "==================\n";
    }
};

class clsDeveloper : public clsEmployee{
private:
    string _MainProgrammingLanguage;
public:
    clsDeveloper(int id, string fName, string lName, string email, string phone, string title, string mainProgLang, double salary)
    : clsEmployee(id, fName, lName, email, phone, title, "Development", salary) 
    {
        _MainProgrammingLanguage = mainProgLang;
    }

    // Setter and Getter methods for modifying and accessing the MainProgrammingLanguage
    void SetMainProgrammingLanguage(string mainProgLang)
    {
        _MainProgrammingLanguage = mainProgLang;
    }
    string GetMainProgrammingLanguage()
    {
        return _MainProgrammingLanguage;
    }

    // Method to print the Developer's information
    // Override function
    void printInfo()
    {
        cout << "Info:\n";
        cout << "==================\n";
        cout << "ID                  : " << GetID() << endl;
        cout << "FirstName           : " << GetFirstName() << endl;
        cout << "LastName            : " << GetLastName() << endl;
        cout << "FullName            : " << GetFullName() << endl;
        cout << "Department          : " << GetDepartment() << endl;
        cout << "Title               : " << GetTitle() << endl;
        cout << "Programming Language: " << _MainProgrammingLanguage << endl;
        cout << "Salary              : " << GetSalary() << endl;
        cout << "Email               : " << GetEmail() << endl;
        cout << "Phone               : " << GetPhone() << endl;
        cout << "==================\n";
    }

};
int main(void)
{
    clsDeveloper dev1(10, "Mahmoud", "Mattar", "mattar@gmail.com", "0101906523", "Software Engineer", "c++", 15000);
    dev1.printInfo();

    dev1.SendEmail("Hi", "How are You");
    dev1.SendSMS("Hi MR Developer");

    cout << dev1.GetMainProgrammingLanguage();
}