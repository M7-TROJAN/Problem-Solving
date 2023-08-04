#include <iostream>
using namespace std;

// Definition of the Person class
class Person {
private:
    int _ID;             // Private member variable to store the person's ID
    string _FirstName;   // Private member variable to store the person's first name
    string _LastName;    // Private member variable to store the person's last name
    string _Email;       // Private member variable to store the person's email
    string _Phone;       // Private member variable to store the person's phone number

public:
    // Constructor to initialize the Person object with provided information
    Person(int id, string firstName, string lastName, string email, string phone) {
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

    // Getter method to access the person's ID
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
};

// Main function
int main() {
    // Create an instance of the Person class named 'per1' with provided information
    Person per1(10, "Mahmoud", "Mattar", "Mahmoud@gmail.com", "01018040635");

    // Call the printInfo() method to display the person's information
    per1.printInfo();

    // Call the SendMessage() method to send an email message
    per1.SendMessage("Hi", "How Are You?");

    // Call the SendSMS() method to send an SMS message
    per1.SendSMS("How Are You?");

    // Pause the program to view the output
    system("pause > nul");

    return 0;
}