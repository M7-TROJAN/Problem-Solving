#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;
int main()
{
  int num = 2; // do not edit 
  while (num < 520) // do not edit
  {
    // Your Code Here

    cout <<num - (num == 2? 1 : 0 ) << "\n";
    if(num == 2)
      num*=2;
    else
      num = num * 2 +2;
  }

  // another solution:

  // int num = 2;
  // while (num < 520) {
  //   if(num == 2)
  //   {
  //     cout << num -1 << "\n";
  //     num*=2;
  //   }
  //   else
  //   {
  //     cout << num << "\n";
  //     num = num *2 +2;
  //   }
  // }
}

// Needed Output
/* 
1
4
10
22
46
94
190
382 
*/