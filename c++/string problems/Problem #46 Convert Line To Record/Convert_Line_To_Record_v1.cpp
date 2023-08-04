#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct stClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

// This function splits a string into words using a delimiter
vector<string> splitString(const string& str, const string& delimiter = " ")
{
    vector<string> words;
    string currentWord;

    // Iterate through the string to extract and add each word to the vector
    size_t delimiterPos = 0;
    string remainingStr = str; // Store the remaining string for manipulation
    while ((delimiterPos = remainingStr.find(delimiter)) != string::npos)
    {
        currentWord = remainingStr.substr(0, delimiterPos);
        if (!currentWord.empty())
        {
            words.push_back(currentWord);
        }
        remainingStr.erase(0, delimiterPos + delimiter.length());
    }

    // Add the last word if it exists
    if (!remainingStr.empty())
    {
        words.push_back(remainingStr);
    }

    return words;
}

bool ConvertLineToRecord(const string& line, stClientData& client, const string& separator = ", ")
{
    vector<string> clientData = splitString(line, separator);
    if (clientData.size() != 5)
    {
        return false; // Error: Incorrect number of data elements
    }
    client.AccountNumber = clientData[0];
    client.PinCode = clientData[1];
    client.Name = clientData[2];
    client.Phone = clientData[3];
    client.AccountBalance = std::stod(clientData[4]);
    return true;
}



void PrintClientRecord(const stClientData& client)
{
    cout << "\nThe following is the extracted client record:\n";
    cout << "Account Number: " << client.AccountNumber << endl;
    cout << "Pin Code: " << client.PinCode << endl;
    cout << "Name: " << client.Name << endl;
    cout << "Phone Number: " << client.Phone << endl;
    cout << "Account Balance: " << client.AccountBalance << endl;
}


int main()
{
    string line = "A150#//#1234#//#Mahmoud Mattar#//#0110203654#//#5270.20";
    cout << "\nLine Record is:\n";
    cout << line << std::endl;

    stClientData client;
    if (ConvertLineToRecord(line, client, "#//#"))
    {
        PrintClientRecord(client);
    }
    else
    {
        cout << "Error: Failed to convert the line record to client data." << std::endl;
    }

    return 0;
}
