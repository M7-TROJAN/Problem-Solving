#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClientData
{
    string name;
    string accountNumber;
    string phoneNumber;
    string pinCode;
    float accountBalance;
};

stClientData ConvertStringClientRecordToStClintData(string stringClientRecord, const string &separator = "#/ /#")
{
    stClientData client;

    size_t separatorPos = 0;

    if ((separatorPos = stringClientRecord.find(separator, 0)) != string::npos)
    {
        client.accountNumber = stringClientRecord.substr(0, separatorPos);
        stringClientRecord.erase(0, separatorPos + separator.length());
    }

    if ((separatorPos = stringClientRecord.find(separator, 0)) != string::npos)
    {
        client.pinCode = stoi(stringClientRecord.substr(0, separatorPos));
        stringClientRecord.erase(0, separatorPos + separator.length());
    }

    if ((separatorPos = stringClientRecord.find(separator, 0)) != string::npos)
    {
        client.name = stringClientRecord.substr(0, separatorPos);
        stringClientRecord.erase(0, separatorPos + separator.length());
    }

    if ((separatorPos = stringClientRecord.find(separator, 0)) != string::npos)
    {
        client.phoneNumber = stringClientRecord.substr(0, separatorPos);
        stringClientRecord.erase(0, separatorPos + separator.length());
    }

    client.accountBalance = stof(stringClientRecord);

    return client;
}

void PrintClientRecord(stClientData client)
{
    cout << "Account Number: " << client.accountNumber << endl;
    cout << "Pin Code: " << client.pinCode << endl;
    cout << "Name: " << client.name << endl;
    cout << "Phone Number: " << client.phoneNumber << endl;
    cout << "Account Balance: " << client.accountBalance << endl;
}

int main()
{
    string stringClientRecord = "A150##123##Mahmoud Mattar##01019060452##5000.0";
    stClientData client1 = ConvertStringClientRecordToStClintData(stringClientRecord, "##");

    // Print the converted data
    PrintClientRecord(client1);

    return 0;
}
