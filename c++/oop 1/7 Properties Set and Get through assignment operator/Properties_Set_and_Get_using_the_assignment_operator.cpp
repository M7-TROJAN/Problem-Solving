#include <iostream>
using namespace std;

class clsPerson {
private:
    string _FirstName;
    string _LastName;
public:
    void setFirstName(string firstName)
    {
        _FirstName = firstName;
    }
    string getFirstName()
    {
        return _FirstName;
    }

    void setLastName(string lastName)
    {
        _LastName = lastName;
    }
    string getLastName()
    {
        return _LastName;
    }

    string getFullName()
    {
        return _FirstName + " " + _LastName;
    }

    // declaration specifier
    __declspec(property(get = getFirstName, put = setFirstName)) string FirstName;
    __declspec(property(get = getLastName, put = setLastName)) string LastName;
    __declspec(property(get = getFullName)) string FullName;
};

int main()
{
    clsPerson person1;

    person1.setFirstName("M7");
    person1.setLastName("Trojan");

    cout << "first name: " << person1.getFirstName() << endl;
    cout << "last name : " << person1.getLastName()  << endl;
    cout << "full name : " << person1.getFullName()  << endl;

    cout << "\n=======================\n\n";

    person1.FirstName = "Mahmoud";
    person1.LastName  = "Mattar";

    cout << "first name: " << person1.FirstName << endl;
    cout << "last name : " << person1.LastName  << endl;
    cout << "full name : " << person1.FullName  << endl;
}

/*
The abbreviation "declspec" stands for "declaration specifier."
It is a specific keyword used in Microsoft Visual C++ to declare special attributes or modifiers for variables, functions, or classes.
The __declspec keyword is primarily used to specify additional information about the properties, storage,
or behavior of the declared entity. In the case of __declspec(property),
it is used to define properties and their associated getter and setter methods in a C++ class.
*/

/*
- __declspec(property) is a Microsoft-specific extension in C++.
- It allows you to define properties for a class, encapsulating data with getter and setter methods.
- Properties provide a convenient way to access and modify class member variables.
- In this code, the properties FirstName, LastName, and FullName are defined using __declspec(property).
- The get and put attributes within __declspec(property) specify the associated getter and setter methods.
- The properties can be accessed and modified directly as if they were regular data members.
- This extension simplifies the creation of properties and improves code readability, especially in Microsoft Visual C++.
- Please note that __declspec(property) is specific to Microsoft's C++ compiler and may not be supported by other compilers like g++ and clang.
*/
