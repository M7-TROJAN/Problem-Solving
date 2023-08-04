
/* Write A Program To PRint 3 Random Numbers From 1 To 10 */
#include <iostream>
#include <cstdlib>
using namespace std;

// Function to generate a random number
int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    for (short i = 0; i < 3; i++)
        cout << RandomNumber(1, 10) << endl;
    
}