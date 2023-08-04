#include <iostream>
using namespace std;

// Definition of the Person class
class clsPerson {
private:
    int _ID;             // Private member variable to store the person's ID
    string _FirstName;   // Private member variable to store the person's first name
    string _LastName;    // Private member variable to store the person's last name
    string _Email;       // Private member variable to store the person's email
    string _Phone;       // Private member variable to store the person's phone number

public:

    // default Constructor
    // we put the default constructor here temporarily because inheritance will use it,
    // in the coming lectures, we will solve the parameterized constructor with inheritance.
    clsPerson(){}

    // Constructor to initialize the Person object with provided information
    clsPerson(int id, string firstName, string lastName, string email, string phone) {
        _ID = id;
        _FirstName = firstName;
        _LastName = lastName;
        _Email = email;
        _Phone = phone;
    }

    // Setter and Getter methods for modifying and accessing the first name
    void SetFirstName(string fName) {
        _FirstName = fName;
    }
    string GetFirstName() {
        return _FirstName;
    }

    // Setter and Getter methods for modifying and accessing the last name
    void SetLastName(string lName) {
        _LastName = lName;
    }
    string GetLastName() {
        return _LastName;
    }

    // Setter and Getter methods for modifying and accessing the email
    void SetEmail(string email) {
        _Email = email;
    }
    string GetEmail() {
        return _Email;
    }

    // Method to get the full name of the person by concatenating first and last name
    string GetFullName() {
        return _FirstName + " " + _LastName;
    }

    // Getter method to access the person's ID (Read Only Property)
    int GetID() {
        return _ID;
    }

    // Setter and Getter methods for modifying and accessing the phone number
    void SetPhone(string phone) {
        _Phone = phone;
    }
    string GetPhone() {
        return _Phone;
    }

    // Method to print the person's information
    void printInfo() {
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
    void SendEmail(string Subject, string Body) {
        cout << "The Following Message Sent Successfully To Email: " << _Email << endl;
        cout << "Subject: " << Subject << "\n";
        cout << "Body: " << Body << endl;
    }

    // Method to send an SMS message
    void SendSMS(string TextMessage) {
        cout << "The Following SMS Sent Successfully To Phone: " << _Phone << endl;
        cout << TextMessage << "\n";
    }
};

/*
Sub Class/Derived Class   Super Class/Base Class */
class clsEmployee : public clsPerson{

    double _Salary;
    string _Department;
    string _Title;

public:
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
};
int main() {

    clsEmployee employee;
    employee.SetFirstName("Mahmoud");
    employee.SetLastName("Mattar");
    employee.SetEmail("matter.gmail.com");
    employee.SetPhone("01045236");
    employee.printInfo();
    employee.SendEmail("Hi", "How are you?");
    employee.SendSMS("Hi");

    employee.SetTitle("Software Engineer");
    employee.SetDepartment("Development");
    employee.SetSalary(15000);

    cout << "Salary: " << employee.GetSalary() << "\n";
    cout << "Title: " << employee.GetTitle() << "\n";
    cout << "Department: " << employee.GetDepartment() << "\n";

    // Calling the print will not print anything from derived class, only base class
    // therfore the print method will not serve me here, this is a problem will be solved in the next lecture.
    employee.printInfo();

    system("pause > nul");

    return 0;
}

// derived → مشتق
// derived class → فئة مشتقة
// sub → فرعي
// Sub Class →  فئة فرعية

// Base → قاعدة / اساسي
// Base Class → الفئة الأساسية

