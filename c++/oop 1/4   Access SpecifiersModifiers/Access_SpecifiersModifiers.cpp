

#include <iostream>
using namespace std;
class clsPerson
{
private:
    // only accessible inside this class
    int Variable1 = 5;

    int Function1()
    {
        return 40;
    }

protected:
    // only accessible inside this class and all classes inherits this class
    int Variable2 = 100;
    int Function2()
    {
        return 50;
    }

public:
    // accessible for everyone outside/inside/and classes inherits this class
    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }
    float Function3()
    {
        return Function1() * Variable1 * Variable2;
    }
};

int main()
{
    clsPerson Person1;
    Person1.FirstName = "Mahmoud";
    Person1.LastName = "Mattar";

    cout << "Person1: " << Person1.FullName() << endl;
    cout << Person1.Function3();
}
/*
Access Specifiers:
In C++, access specifiers control the visibility and accessibility of class members.
They determine which parts of a class are accessible from different contexts.

- private: The private access specifier restricts access to class members to be only within the class itself.
They are not accessible from outside the class or from derived classes. Private members are typically used for internal implementation details
that are not intended to be accessed directly.

- protected: The protected access specifier allows access to class members within the class itself and any derived classes.
They are not accessible from outside the class hierarchy. Protected members are often used to provide access to derived classes
while still restricting access from other parts of the program.

- public: The public access specifier provides unrestricted access to class members from any part of the program.
Public members can be accessed directly from outside the class and are inherited by derived classes.
They are typically used for interface and functionality that needs to be accessible to other parts of the program.

By default, if no access specifier is specified, members are considered private.

It's important to carefully choose the appropriate access specifier for class members based on the desired level of encapsulation
and the intended usage of the class.

Note: The access specifiers only affect the visibility of class members;
they do not impact the memory layout or size of the class or object in memory.
*/
