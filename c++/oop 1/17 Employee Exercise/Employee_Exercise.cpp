#include <iostream>
using namespace std;

class clsEmployee
{
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Title;
    string _Email;
    string _Phone;
    string _Department;
    double _Salary;

public:
    clsEmployee(int id, string fName, string lName, string title, string email, string phone, double salary, string department)
    {
        _ID = id;
        _FirstName = fName;
        _LastName = lName;
        _Title = title;
        _Email = email;
        _Phone = phone;
        _Salary = salary;
        _Department = department;
    }

    // Getter method to access the person's ID
    // Getter methods are made const to ensure they don't modify the object's state
    int GetID() {
        return _ID;
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

    // Setter and Getter methods for modifying and accessing the title
    void SetTitle(string title) {
        _Title = title;
    }
    string GetTitle() {
        return _Title;
    }

    // Setter and Getter methods for modifying and accessing the email
    void SetEmail(string email) {
        _Email = email;
    }
    string GetEmail() {
        return _Email;
    }

    // Setter and Getter methods for modifying and accessing the phone number
    void SetPhone(string phone) {
        _Phone = phone;
    }
    string GetPhone() {
        return _Phone;
    }

    // Setter and Getter methods for modifying and accessing the salary
    void SetSalary(double salary) {
        _Salary = salary;
    }
    double GetSalary() {
        return _Salary;
    }

    // Setter and Getter methods for modifying and accessing the Department
    void SetDepartment(string department) {
        _Department = department;
    }
    string GetDepartment() {
        return _Department;
    }

    // Method to get the full name of the person by concatenating first and last name
    string GetFullName() {
        return _FirstName + " " + _LastName;
    }

    // Method to send an email message
    void SendMessage(string Subject, string Body) {
        cout << "The Following Message Sent Successfully To Email: " << _Email << endl;
        cout << "Subject: " << Subject << "\n";
        cout << "Body: " << Body << endl;
    }

    // Method to send an SMS message
    void SendSMS(string TextMessage) {
        cout << "The Following SMS Sent Successfully To Phone: " << _Phone << endl;
        cout << TextMessage << "\n";
    }

    // Method to print the Employee's information
    void printInfo() {
        cout << "Info:\n";
        cout << "==================\n";
        cout << "ID: " << _ID << endl;
        cout << "FirstName: " << _FirstName << endl;
        cout << "LastName: " << _LastName << endl;
        cout << "FullName: " << GetFullName() << endl;
        cout << "Title: " << _Title << endl;
        cout << "Salary: $" << _Salary << endl;
        cout << "Department: " << _Department << endl;
        cout << "Email: " << _Email << endl;
        cout << "Phone: " << _Phone << endl;
        cout << "==================\n";
    }
};

int main()
{
    // Create an instance of the clsEmployee class named 'emp1' with provided information
    clsEmployee emp1(10, "Mahmoud", "Mattar", "Software Engineer", "mahmoud@M7Trojan.com", "0101406", 15000, "Development");

    // Call the printInfo() method to display the Employee's information
    emp1.printInfo();

    // Call the SendMessage() method to send an email message
    emp1.SendMessage("Hi", "How Are You?");

    // Call the SendSMS() method to send an SMS message
    emp1.SendSMS("How Are You?");

    // Pause the program to view the output
    system("pause > nul");

    clsEmployee emp2 = emp1;

    emp1 = emp2;

}