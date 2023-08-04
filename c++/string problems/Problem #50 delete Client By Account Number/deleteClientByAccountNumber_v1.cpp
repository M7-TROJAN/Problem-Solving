#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;
const string ClientsFileName = "Clients.txt";
struct stClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

char get_char(std::string message = "")
{
    char letter = ' ';
    std::cout << message;
    std::cin >> letter;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return letter;
}

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

string readClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber: ";
    cin >> AccountNumber;
    return AccountNumber;
}

void PrintClientCard(stClientData Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

void removeLineFromFile(const string& filename, int lineToRemove)
{
    ifstream originalFile(filename);
    if (!originalFile) {
        cerr << "Failed to open input file: " << filename << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Failed to create temporary file." << endl;
        originalFile.close();
        return;
    }

    string line;
    int lineCount = 1;
    while (getline(originalFile, line)) {
        if (lineCount != lineToRemove)
            tempFile << line << endl;
        lineCount++;
    }

    originalFile.close();
    tempFile.close();

    // Delete the original file
    remove(filename.c_str());

    // Rename the temporary file to the original filename
    rename("temp.txt", filename.c_str());
}

void deleteClientByAccountNumber(const string &AccountNumber)
{
    ifstream file(ClientsFileName);
    if (file.is_open())
    {
        stClientData client;
        string line;
        int lineNumber = 1;
        char sureToDelete = 'y';
        while (getline(file, line))
        {
            if (line.substr(0,AccountNumber.length()) == AccountNumber)
            {
                ConvertLineToRecord(line, client, "##");
                PrintClientCard(client);
                sureToDelete = get_char("\nAre You Sure You Want TO Delete This Clint (y / n)?: ");
                if(tolower(sureToDelete) == 'y')
                {
                    file.close();
                    removeLineFromFile(ClientsFileName, lineNumber);
                    cout << "\n\nClient Deleted Successfully.\n";
                }
                return;
            }
            lineNumber++;
        }
        file.close();
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
    else
    {
        std::cerr << "Error opening file: " << ClientsFileName << std::endl;
    }
}

int main()
{
    // deleteClientByAccountNumber( readClientAccountNumber() );

    string AccountNumber = readClientAccountNumber();
    deleteClientByAccountNumber(AccountNumber);

    return 0;
}