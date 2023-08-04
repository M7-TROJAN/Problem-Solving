#include <iostream>
using namespace std;
int main()
{

    auto x = 10;               // Type Integer
    auto y = 12.5;             // Type Double
    auto z = "Mahmoud Mattar"; // Type String
    auto b = true;             // Type boolean
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << b << endl;
    return 0;
}

/* Lesson 21: Automatic Variables :

Note1: if The Compiler See (auto) --> He Will Look To The  unsigned Value (القيمة غير الموقًعة)
And Guess The Type Of it ,Then Save The (Type) Of it in The Memory !

Note2: Don't Use The (auto Variables) Never ! --> Because The Usual Way Of defining(تعريف) The Variables -->
is Better And Easier And Quiq , And You Can Know The Better Size Of The Defined(المعرًفة) Variables At The Memory ! 

*/