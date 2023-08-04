#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
const string ClientsFileName = "D:\\Clients.txt";
struct stClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
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

bool ConvertLineToRecord(const string &line, stClientData &client, const string &separator = ", ")
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

vector<stClientData> LoadClientsDataFromFile(const string &filePath)
{
    vector<stClientData> vClients;
    std::ifstream file(filePath);
    if (file.is_open())
    {
        std::string line;
        stClientData client;
        while (std::getline(file, line))
        {
            if (ConvertLineToRecord(line, client, "##"))
            {
                vClients.push_back(client);
            }
            else
            {
                std::cerr << "Unexpected Error While Reading Clients Line.: " << std::endl;
                break;
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
    return vClients;
}

void PrintClientRecord(stClientData Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(const vector<stClientData> &vClients)
{
    cout << "\n\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"<< endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"<< endl;
    for (stClientData Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"<< endl;
}

int main()
{
    vector<stClientData> vClients = LoadClientsDataFromFile(ClientsFileName);

    PrintAllClientsData(vClients);

    return 0;
}
