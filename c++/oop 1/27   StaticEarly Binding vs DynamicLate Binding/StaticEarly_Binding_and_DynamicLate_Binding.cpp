// Static Binding vs Dynamic Binding
// Binding means → ربط
#include <iostream>

using namespace std;

class clsPerson
{

public:
    virtual void Print()

    {
        cout << "Hi, i'm a person!\n ";
    }
};

class clsEmployee : public clsPerson
{
public:
    void Print() override
    {
        cout << "Hi, I'm an Employee\n";
    }
};

class clsStudent : public clsPerson
{
public:
    void Print() override
    {
        cout << "Hi, I'm a student\n";
    }
};

int main()

{

    clsEmployee Employee1;
    clsStudent Student1;
    // Early-Static Binding: at compilation time
    Employee1.Print();
    Student1.Print();

    clsPerson *Person1 = &Employee1;
    clsPerson *Person2 = &Student1;

    // Late-Dynamic Binding: at runtime
    Person1->Print();
    Person2->Print();

    system("pause > nul");
    return 0;
}

/*
Note:
'Static Binding'  is the  'Early Binding' They both have the same meaning and concept.
'Dynamic Binding' is the  'Late Binding' They both have the same meaning and concept.

*/