#include <iostream>
using namespace std;

// Write Your Function Here
string swapping(string text)
{
    for (short i = 0; i < text.length(); i++)
    {
        if(text[i] == 'H' || text[i] == 'h')
            continue;
        if(text[i] >= 'a' && text[i] <= 'z' )
            text[i]-=32;
        else if(text[i] >= 'A' && text[i] <= 'Z' )
            text[i]+=32;
    }
    return text;
    
}
int main()
{
    cout << swapping("hero Of THe PROgramming") << "\n"; // hERO oF tHE proGRAMMING
    return 0;
}