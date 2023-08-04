#include <iostream>
using namespace std;

class clsPerson {
public:
    string firstName;
    string lastName;
    string fName; // fName is not initialized here

    void setFullName() {
        fName = firstName + " " + lastName; // Concatenate firstName and lastName
    }
};

int main() {
    clsPerson person;
    person.firstName = "Mahmoud";
    person.lastName = "Mattar";

    person.setFullName(); // Call the function to set the fullName

    cout << person.fName << endl;
    return 0;
}
