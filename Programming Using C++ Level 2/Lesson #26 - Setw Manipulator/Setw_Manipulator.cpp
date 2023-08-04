#include <iostream>
#include <iomanip> // this library stored the std::setw
using namespace std; 
int main() 
{ 
    cout << "----------|--------------------------------|----------|" << endl; 
    cout << "   Code   |            Name                |   Mark   |" << endl; 
    cout << "--------- |--------------------------------|----------|" << endl; 

    cout << setw(10) << "C101"     << "|" << setw(32) << "introduction to Programming" << "|" << setw(10) << "95" << "|" << endl; 
    cout << setw(10) << "C102"     << "|" << setw(32) << "Computer Hardware"           << "|" << setw(10) << "88" << "|" << endl; 
    cout << setw(10) << "C1035243" << "|" << setw(32) << "Network"                     << "|" << setw(10) << "75" << "|" << endl; 
    cout << "--------- |--------------------------------|----------|" << endl; 

return 0; 
}