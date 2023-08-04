#include <vector>
#include <iostream>
using namespace std;
void ReadNumbers(vector<int> &vNumbers)
{
    char ReadMore = 'Y';
    int Number;
    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        cout << "Please enter a number? ";
        cin >> Number;
        vNumbers.push_back(Number);
        cout << "\nDo you want to read more numbers? Y/N ?";
        cin >> ReadMore;
    }
}
void PrintVectorNumbers(vector<int> &vNumbers)
{
    cout << "Numbers Vector: \n\n";
    for (int Number : vNumbers)
    {
        cout << Number << endl;
    }
    cout << endl;
}
int main()
{
    vector<int> vNumbers;
    ReadNumbers(vNumbers);
    PrintVectorNumbers(vNumbers);
    return 0;
}