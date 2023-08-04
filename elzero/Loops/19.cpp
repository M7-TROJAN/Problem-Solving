#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;
int main()
{
  // Output Needed
/*
100
200
200
300
300
400
400
500
500
600
600
700
700
800
800
900
900
1000
1000
1100
*/

  for (size_t i = 100; i <= 1100; i+=100)
  {
    if (i > 100 && i < 1100)
      cout << i <<"\n";
    cout << i << "\n";
  }
  
}