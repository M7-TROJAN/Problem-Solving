#include <iostream>
using namespace std;

class clsPerson{
private:
    int _ID = 10;
    string _FirstName;
    string _LastName;
public:
    //Property Get, this is a read only property because we don’t have a set function 
    int getID()
    {
        return _ID;
    }

    // Property Set: Sets the value of the first name
    void setFirstName(string firstName)
    {
        _FirstName = firstName;
    }
    // Property Get: Retrieves the value of the first name
    string getFirstName()
    {
        return _FirstName;
    }

    // Property Set: Sets the value of the last name
    void setLastName(string lastName)
    {
        _LastName = lastName;
    }
    // Property Get: Retrieves the value of the last name
    string getLastName()
    {
        return _LastName;
    }

    string getFullName()
    {
        return _FirstName + " "  + _LastName;
    }
};
int main()
{
    clsPerson person1;
    person1.setFirstName("Mahmoud");
    person1.setLastName("Mattar");

    cout << "ID: " << person1.getID() << endl;
    cout << "First Name: " << person1.getFirstName() << endl;
    cout << "Last Name: " << person1.getLastName() << endl;
    cout << "Full Name: " << person1.getFullName() << endl;

    system("pause > nul");
    return 0;
}