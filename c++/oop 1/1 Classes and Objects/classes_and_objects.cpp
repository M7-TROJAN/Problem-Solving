#include <iostream>
using namespace std;
class clsPerson
{
    // this private and will not be accessed from outside the class
    // for internal use only
    int x;

public:
    string FirstName;
    string LastName;
    string FullName()
    {
        FirstName[0] = toupper(FirstName[0]);
        LastName[0] = toupper(LastName[0]);
        return FirstName + " " + LastName;
    }
    string ReverseName()
    {
        FirstName[0] = toupper(FirstName[0]);
        LastName[0] = toupper(LastName[0]);
        return LastName + " " + FirstName;
    }
};

int main()
{
    clsPerson Person1;
    Person1.FirstName = "mahmoud";
    Person1.LastName = "mattar";
    cout << Person1.FullName() << endl;
    cout << Person1.ReverseName() << endl;
}
