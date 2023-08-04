#include <iostream>
using namespace std;

// Abstract Class / Interface / Contract -> عقد.
class clsMobile
{
    virtual void Dial(string PhoneNumber) = 0;
    virtual void SendSMS(string PhoneNumber, string Text) = 0;
    virtual void TakePicture() = 0;
};

class clsIPhone : public clsMobile
{

    // This class signed a contract with clsMobile abstract class   therefore it should implement everything in the abstract class

public:
    void Dial(string PhoneNumber){

    };

    void SendSMS(string PhoneNumber, string Text){

    };

    void TakePicture(){

    };

    // Derived Classes from abstract class can have extra methods other than the methods in the abstract class.
    void MyOwnMethod()
    {
    }
};

class clsSamsungNote10 : public clsMobile
{
    // This class signed a contract with clsMobile abstract class   therefore it should implement everything in the abstract class

public:
    void Dial(string PhoneNumber){

    };

    void SendSMS(string PhoneNumber, string Text){

    };

    void TakePicture(){

    };
};

int main()

{
    clsIPhone iPhone1;
    clsSamsungNote10 Note10;

    system("pause > nul");
    return 0;
}