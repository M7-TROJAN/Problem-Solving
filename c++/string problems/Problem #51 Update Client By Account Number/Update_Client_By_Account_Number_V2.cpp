
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const string ClientsFileName = "Clients.txt";
struct stClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
// This function splits a string into words using a delimiter
vector<string> splitString(const string &str, const string &delimiter = " ")
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

stClientData ConvertLineToRecord(string Line, string Separator = "##")
{
    stClientData Client;
    vector<string> vClientData;
    vClientData = splitString(Line, Separator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double
    return Client;
}

string ConvertRecordToLine(stClientData Client, string Separator = "##")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.Name + Separator;
    stClientRecord += Client.Phone + Separator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

vector<stClientData> LoadClientsDataFromFile(string FileName)
{
    vector<stClientData> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode
    if (MyFile.is_open())
    {
        string Line;
        stClientData Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}
void PrintClientCard(stClientData Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClientData> vClients, stClientData &Client)
{
    for (stClientData C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}
stClientData ChangeClientRecord(string AccountNumber)
{
    stClientData Client;
    Client.AccountNumber = AccountNumber;
    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

vector<stClientData> SaveClientsDataToFile(string FileName, vector<stClientData> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // overwrite
    string DataLine;
    if (MyFile.is_open())
    {
        for (stClientData C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                // we only write records that are not marked for
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClientData> &vClients)
{
    stClientData Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (stClientData &C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    return false;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}
int main()
{
    vector<stClientData> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
    system("pause>0");
    return 0;
}