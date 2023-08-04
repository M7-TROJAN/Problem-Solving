#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
struct stClintData
{
    string name;
    string accountNumber;
    string phoneNumber;
    string pinCode;
    float accountBalance;
};

string getString(const string &message = "")
{
    string str;
    cout << message;
    getline(cin, str);
    return str;
}

string readPinCode(std::string message = "Please Enter Pin Code: ")
{
    std::string pinCode = "";
    do
    {
        std::cout << message;
        std::cin >> pinCode;

        // Check if the input was invalid
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        if(pinCode.length() != 4 )
        {
            cerr << "Invalid Input, Pin Code Should Be 4 Numeric Digits.";
            continue;
        }

        if(!isdigit(pinCode[0]) || !isdigit(pinCode[1]) || !isdigit(pinCode[2]) || !isdigit(pinCode[3]))
        {
            cerr << "Invalid Input, Pin Code Should Be 4 Numeric Digits.";
            continue;
        }
        break;
    } while (true);
    return pinCode;
}

std::string readPhoneNumber(const std::string& message = "Please enter phone number: ")
{
    std::string phoneNumber;

    while (true)
    {
        std::cout << message;
        std::cin >> phoneNumber;

        if (std::cin.fail() || phoneNumber.length() != 11 || !std::all_of(phoneNumber.begin(), phoneNumber.end(), isdigit))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input! Phone number should be a 11-digit numeric value." << std::endl;
        }
        else
        {
            break;
        }
    }
    return phoneNumber;
}

float get_float(const string &message = "")
{
    float number = 0;
    do
    {
        cout << message;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    } while (true);
    return number;
}

stClintData ReadNewClintData()
{
    stClintData clint;
    std::cout << "Please Enter Clint Data:\n";

    clint.name = getString("Enter Name: ");
    clint.accountNumber = getString("Enter Account Number: ");
    clint.phoneNumber = readPhoneNumber();
    clint.pinCode = readPinCode();
    clint.accountBalance = get_float("Enter Account Balance: ");

    return clint;
}

string convertRecordToLine(const stClintData &client, const string &Separator = ", ")
{
    string stringClientRecord;

    stringClientRecord += client.accountNumber + Separator;
    stringClientRecord += client.pinCode + Separator;
    stringClientRecord += client.name + Separator;
    stringClientRecord += client.phoneNumber + Separator;
    stringClientRecord += to_string(client.accountBalance);

    return stringClientRecord;
}

int main()
{
    stClintData clint1 = ReadNewClintData();

    cout << "\nClient Record for Saving is:\n";

    cout << convertRecordToLine(clint1, "##");
}

