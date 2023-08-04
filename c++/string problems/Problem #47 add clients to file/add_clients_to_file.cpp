#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;
const string ClientsFileName = "D:\\Clients.txt";
struct stClintData
{
    string name;
    string accountNumber;
    string phoneNumber;
    string pinCode;
    float accountBalance;
};

int get_int(const string &message = "")
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    } while (true);
    return number;
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
            std::cin.ignore(10000, '\n');
            // cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }
        break;
    } while (true);
    return number;
}

char get_char(std::string message = "")
{
    char letter = ' ';
    std::cout << message;
    std::cin >> letter;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return letter;
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
void AddDataLineToFile(const string &fileName, const string &stringClientRecord)
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

stClintData ReadNewClintData()
{
    stClintData client;
    std::cout << "Please Enter Clint Data:\n";

    cout << "Enter Account Number: ";
    getline(cin >> ws, client.accountNumber); // Usage of std::ws will extract all the whitespace character

    client.pinCode = get_int("Enter Pin Code: ");

    cout << "Enter Name: ";
    getline(cin, client.name);

    cout << "Enter Phone Number: ";
    getline(cin, client.phoneNumber);

    client.accountBalance = get_double("Enter Account Balance: ");

    return client;
}

void AddNewClient()
{
    stClintData Client;
    Client = ReadNewClintData();
    AddDataLineToFile(ClientsFileName, convertRecordToLine(Client, "##"));
}

void AddClients()
{
    char AddMore = 'y';
    do
    {
        system("cls");
        cout << "Adding New Client:\n";
        AddNewClient();
        AddMore = get_char("Do You Want To add More Clients (y/n)?: ");
    } while (tolower(AddMore) == 'y');
}

int main()
{
    AddClients();
}
