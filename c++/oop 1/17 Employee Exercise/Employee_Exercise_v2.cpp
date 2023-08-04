#include <iostream>
#include <string>

class clsEmployee {
private:
    int _ID = 0;
    std::string _FirstName = "";
    std::string _LastName = "";
    std::string _Title = "";
    std::string _Email = "";
    std::string _Phone = "";
    std::string _Department = "";
    double _Salary = 0.0;

public:
    clsEmployee() = default; // Default constructor

    clsEmployee(int id, std::string fName, std::string lName, std::string title,
                std::string email, std::string phone, double salary, std::string department)
        : _ID(id), _FirstName(std::move(fName)), _LastName(std::move(lName)),
          _Title(std::move(title)), _Email(std::move(email)), _Phone(std::move(phone)),
          _Salary(salary), _Department(std::move(department)) {}

    // Getter methods are made const to ensure they don't modify the object's state
    int GetID() const {
        return _ID;
    }

    std::string GetFirstName() const {
        return _FirstName;
    }

    std::string GetLastName() const {
        return _LastName;
    }

    std::string GetTitle() const {
        return _Title;
    }

    std::string GetEmail() const {
        return _Email;
    }

    std::string GetPhone() const {
        return _Phone;
    }

    double GetSalary() const {
        return _Salary;
    }

    std::string GetDepartment() const {
        return _Department;
    }

    std::string GetFullName() const {
        return _FirstName + " " + _LastName;
    }

    void SendMessage(const std::string& subject, const std::string& body) const {
        std::cout << "The Following Message Sent Successfully To Email: " << _Email << std::endl;
        std::cout << "Subject: " << subject << std::endl;
        std::cout << "Body: " << body << std::endl;
    }

    void SendSMS(const std::string& textMessage) const {
        std::cout << "The Following SMS Sent Successfully To Phone: " << _Phone << std::endl;
        std::cout << textMessage << std::endl;
    }

    void printInfo() const {
        std::cout << "Info:" << std::endl;
        std::cout << "==================" << std::endl;
        std::cout << "ID: " << _ID << std::endl;
        std::cout << "FirstName: " << _FirstName << std::endl;
        std::cout << "LastName: " << _LastName << std::endl;
        std::cout << "FullName: " << GetFullName() << std::endl;
        std::cout << "Title: " << _Title << std::endl;
        std::cout << "Salary: $" << _Salary << std::endl;
        std::cout << "Department: " << _Department << std::endl;
        std::cout << "Email: " << _Email << std::endl;
        std::cout << "Phone: " << _Phone << std::endl;
        std::cout << "==================" << std::endl;
    }
};

int main() {
    // Create an instance of the clsEmployee class named 'emp1' with provided information
    clsEmployee emp1(10, "Mahmoud", "Mattar", "Software Engineer", "mahmoud@M7Trojan.com",
                     "0101406", 15000, "Development");

    // Call the printInfo() method to display the Employee's information
    emp1.printInfo();

    // Call the SendMessage() method to send an email message
    emp1.SendMessage("Hi", "How Are You?");

    // Call the SendSMS() method to send an SMS message
    emp1.SendSMS("How Are You?");

    // Pause the program to view the output
    system("pause > nul");
}
