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
        cout << "ID: " << GetID() << endl;
        cout << "FirstName: " << GetFirstName() << endl;
        cout << "LastName: " << GetLastName() << endl;
        cout << "FullName: " << GetFullName() << endl;
        cout << "Email: " << GetEmail() << endl;
        cout << "Phone: " << GetPhone() << endl;
        cout << "Title: " << GetTitle() << endl;
        cout << "Department: " << GetDepartment() << endl;
        cout << "Salary: " << GetSalary() << endl;
        cout << "==================\n";
    }
};

int main(void)
{
    clsEmployee Employee1(10, "Mahmoud", "Mattar", "mattar@gmail.com", "0101906523", "Software Engineer", "Development", 15000);
    Employee1.printInfo();
}
/*
overriding → تجاوز
Function overriding is a concept in object-oriented programming (OOP) where a subclass provides a specific implementation for a method
that is already defined in its superclass. When a subclass defines a method with the same name and function signature
(i.e., the same return type and parameters) as a method in its superclass, it overrides the behavior of the superclass method.

In other words, function overriding allows a subclass to provide its own specialized implementation of a method, which is different from the implementation in the superclass.
When an object of the subclass calls the overridden method, it will execute the subclass's implementation instead of the superclass's implementation.

Overriding is commonly used in inheritance scenarios, where a subclass inherits properties and methods from its superclass.
By overriding methods, the subclass can customize or extend the behavior of its parent class, while still retaining the other features of the superclass.

when we say "overriding something" in the context of function overriding, it does not necessarily mean canceling or deleting the original method.
Instead, it means providing a new implementation that takes precedence over the original implementation in certain situations.
The original method still exists in the superclass, but when called on an object of the subclass, the overridden method in the subclass will be executed instead.
*/