#include <iostream>
using namespace std;

class clsAddress{
private:
    string _AddressLine1;
    string _AddressLine2;
    string _PoBox;
    string _ZipCode;
public:
    clsAddress(string AddressLine1, string AddressLine2, string PoBox, string ZipCode) : _AddressLine1(AddressLine1), _AddressLine2(AddressLine2),
    _PoBox(PoBox),  _ZipCode(ZipCode){}

    void setAddressLine1(string AddressLine1)
    {
        _AddressLine1 = AddressLine1;
    }
    void setAddressLine2(string AddressLine2)
    {
        _AddressLine2 = AddressLine2;
    }
    void setPoBox(string PoBox)
    {
        _PoBox = PoBox;
    }
    void setZipCode(string ZipCode)
    {
        _ZipCode = ZipCode;
    }

    string getAddressLine1(string AddressLine1)
    {
        return _AddressLine1;
    }
    string getAddressLine2(string AddressLine2)
    {
        return _AddressLine2;
    }
    string getPoBox(string PoBox)
    {
        return _PoBox;
    }
    string getZipCode(string ZipCode)
    {
        return _ZipCode;
    }

    void PrintDetails()
    {
        cout << "\nAddress Details:\n";
        cout << "----------------\n";
        cout << "AddressLine1: " << _AddressLine1 << endl;
        cout << "AddressLine2: " << _AddressLine2 << endl;
        cout << "PoBox: "        << _PoBox << endl;
        cout << "ZipCode: "        << _ZipCode << endl;
    }

};

int main()
{
    clsAddress Address("Egypt, Cairo", "Nasser City", "1234", "0012");
    Address.PrintDetails();

    Address.setAddressLine1("Egypt, Sharqia");
    Address.setAddressLine2("Abu Hammad");
    Address.setPoBox("5243");
    Address.setZipCode("8962");
    Address.PrintDetails();
}

/*
'The word constructor' came from Construction
constructor means → منشيئ
*/