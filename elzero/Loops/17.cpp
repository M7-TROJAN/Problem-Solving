#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;
int main()
{
  for(int i = 1 ; i <= 102 ; i++)
  {
    if (i < 10)
      cout << 0 << 0;
    else if( i >= 10 && i < 100)
      cout << 0;
    cout << i << "\n";
  }
// Output Needed
/*
001
002
003
004
005
006
007
008
009
010
011
012
013
014
015
016
017
018
019
020
100
101
102
*/
}