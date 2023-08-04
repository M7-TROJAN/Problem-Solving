#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct persons
{
    string name;
    int age;
};

int main()
{
    persons person1;
    person1.age = 14;
    person1.name = "mahmoud";
    
    fstream myFile;
    myFile.open("myFile.txt", ios::out);

    if (myFile.is_open())
    {
        myFile << person1.name << endl;
        myFile << person1.age << endl;
        
        myFile.close();
        cout << "Data written to the file successfully." << endl;
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }

    return 0;
}
