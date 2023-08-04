#include <iostream>
#include <cctype>
using namespace std;

// Write Your Function Here
string greeting(string name, string gender = "")
{
    for(int i = 0 ; i < gender.length(); i++)
        gender[i] = tolower(gender[i]);
    
    if(gender == "female" || gender == "f")
        return "Hello Miss " + name;
    else if(gender == "male" || gender == "m")
        return "Hello Mr " + name;
    else
        return "Hello " + name;
}
int main()
{
    cout << greeting("Osama", "Male") << "\n";  // Hello Mr Osama
    cout << greeting("Eman", "Female") << "\n"; // Hello Miss Eman
    cout << greeting("Sameh") << "\n";          // Hello Sameh
    return 0;
}