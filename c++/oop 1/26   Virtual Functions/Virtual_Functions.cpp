// Virtual Functions
// Virtual means → افتراضي so Virtual Functions means → الوظائف الافتراضية

#include <iostream>
using namespace std;

class clsPerson {
public:
    virtual void Print() {
        cout << "Hi, I'm a person!" << endl;
    }
};

class clsEmployee : public clsPerson {
public:
    void Print() override {
        cout << "Hi, I'm an Employee!" << endl;
    }
};

class clsStudent : public clsPerson {
public:
    void Print() override {
        cout << "Hi, I'm a student!" << endl;
    }
};

int main() {
    clsEmployee Employee1;
    clsStudent Student1;

    Employee1.Print(); // Output: Hi, I'm an Employee!
    Student1.Print();  // Output: Hi, I'm a student!

    clsPerson* Person1 = &Employee1;
    clsPerson* Person2 = &Student1;

    Person1->Print(); // Output: Hi, I'm an Employee! (dynamic binding) 
    Person2->Print(); // Output: Hi, I'm a student! (dynamic binding)
    // Note: If you don't write the keyword 'virtual' before the 'Print' function declaration in the base class, the output will be:
    // Hi, I'm a person!
    // Hi, I'm a person!

    system("pause > nul");
    return 0;
}
