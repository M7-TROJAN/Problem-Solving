#include <iostream>
using namespace std;

class clsPerson
{
private:
    string _FirstName;
    string _LastName;

public:
    // Property Set: Sets the value of the first name
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    // Property Get: Retrieves the value of the first name
    string FirstName()
    {
        return _FirstName;
    }

    // Property Set: Sets the value of the last name
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    // Property Get: Retrieves the value of the last name
    string LastName()
    {
        return _LastName;
    }

    // Returns the full name by concatenating the first and last names
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }
};

int main()
{
    clsPerson Person1;
    Person1.setFirstName("Mahmoud");
    Person1.setLastName("Mattar");

    cout << "First Name: " << Person1.FirstName() << endl;
    cout << "Last Name: " << Person1.LastName() << endl;
    cout << "Full Name: " << Person1.FullName() << endl;

    system("pause > nul");
    return 0;
}


/*
In object-oriented programming, Property Set and Get methods are used to encapsulate the access and manipulation of private member variables (properties) of a class.
They provide a controlled way to set and retrieve the values of these variables.

explanation of Property Set and Get:

Property Set (Setter):

A Property Set method is responsible for setting the value of a private member variable.
It usually takes a parameter that represents the new value to be assigned.
Inside the setter method, you can perform any necessary validation or additional logic before assigning the value to the member variable.

Property Get (Getter):

A Property Get method is used to retrieve the value of a private member variable.
It does not take any parameters.
The getter method returns the current value of the member variable.

By using Property Set and Get methods, you can enforce encapsulation and control the access to the internal state of an object
This approach allows you to protect the integrity of the object's data and provide a standardized way for other code to interact with the object's properties.

In the provided code, the Property Set methods (setFirstName and setLastName)
are used to set the values of the private member variables _FirstName and _LastName, respectively.
The Property Get methods (FirstName and LastName) are used to retrieve the values of these member variables.

Using Property Set and Get methods helps promote encapsulation and maintain the principle of information hiding within a class.

*/