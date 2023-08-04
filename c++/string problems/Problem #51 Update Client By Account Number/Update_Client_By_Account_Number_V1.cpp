#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;
const string ClientsFileName = "Clients.txt";
struct stClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0.0;
};

char get_char(std::string message = "")
{
    char letter = ' ';
    std::cout << message;
    std::cin >> letter;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return letter;
}

double get_double(std::string message = "")
{
    double number = 0;
    do
    {
        // Read a double value from the user
        std::cout << message;
        std::cin >> number;

        // Check if the input was invalid (i.e. not an number)
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    } while (true);
    return number;
}

std::string readPinCode(const std::string& message = "Please enter Pin Code: ")
{
    std::string pinCode;

    while (true)
    {
        std::cout << message;
        std::cin >> pinCode;

        // Check if the input was invalid
        if (std::cin.fail() || pinCode.length() != 4 || !std::all_of(pinCode.begin(), pinCode.end(), isdigit))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input! Pin Code should be a 4-digit numeric value." << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return phoneNumber;
}

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

void removeLineFromFile(const std::string& filename, int lineToRemove)
{
    std::ifstream originalFile(filename);
    if (!originalFile) {
        std::cerr << "Failed to open input file: " << filename << std::endl;
        return;
    }

    std::ofstream tempFile("temp.txt");
    if (!tempFile) {
        std::cerr << "Failed to create temporary file." << std::endl;
        originalFile.close();
        return;
    }

    std::string line;
    int lineCount = 1;
    while (std::getline(originalFile, line)) {
        if (lineCount != lineToRemove)
            tempFile << line << std::endl;
        lineCount++;
    }

    originalFile.close();
    tempFile.close();

    // Delete the original file
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Failed to delete the original file: " << filename << std::endl;
        return;
    }

    // Rename the temporary file to the original filename
    if (std::rename("temp.txt", filename.c_str()) != 0) {
        std::cerr << "Failed to rename the temporary file." << std::endl;
        return;
    }
}


string convertRecordToLine(const stClientData& client, const string& Separator = ", ")
{
    string stringClientRecord;

    stringClientRecord += client.AccountNumber + Separator;
    stringClientRecord += client.PinCode + Separator;
    stringClientRecord += client.Name + Separator;
    stringClientRecord += client.Phone + Separator;
    stringClientRecord += to_string(client.AccountBalance);

    return stringClientRecord;
}

void AddDataLineToFile(const string& fileName, const string& stringClientRecord)
{
    fstream ClientsInfoFile;
    ClientsInfoFile.open(fileName, ios::app);
    if (ClientsInfoFile.is_open())
    {
        if (!stringClientRecord.empty())
        {
            ClientsInfoFile << stringClientRecord << "\n";
            cout << "Client Added Successfully.\n";
        }
        else
            cout << "Error: the line record Is Empty." << endl;
        ClientsInfoFile.close();
    }
    else
    {
        cout << "Error: Failed to Open the File." << endl;
    }
}

stClientData ChangeClientRecord(string AccountNumber)
{
    stClientData client;
    client.AccountNumber = AccountNumber;

    client.PinCode = readPinCode("Enter Pin Code: ");
    
    cout << "Enter Name: ";
    getline(cin, client.Name);

    client.Phone = readPhoneNumber("Enter Phone Number: ");

    client.AccountBalance = get_double("Enter Account Balance: ");

    return client;
}

void updateClientByAccountNumber(const string& AccountNumber)
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
            if (line.substr(0, AccountNumber.length()) == AccountNumber)
            {
                ConvertLineToRecord(line, client, "##");
                PrintClientCard(client);
                sureToDelete = get_char("\nAre You Sure You Want TO Update This Clint (y / n)?: ");
                if (tolower(sureToDelete) == 'y')
                {
                    file.close();
                    removeLineFromFile(ClientsFileName, lineNumber);
                    client = ChangeClientRecord(AccountNumber);
                    AddDataLineToFile(ClientsFileName, convertRecordToLine(client, "##"));
                    cout << "\n\nClient Updated Successfully.\n";
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
    string AccountNumber = readClientAccountNumber();
    updateClientByAccountNumber(AccountNumber);

    return 0;
}