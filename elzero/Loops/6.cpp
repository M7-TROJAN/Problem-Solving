#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
  for(long i = 10 ; i <= 100000000 ; i*=i )
    cout << i << "\n";

  long i = 10;
  while (i <= 100000000)
  {
    cout << i << "\n";
    i*=i;
  }
  
}
// Output Needed
/*
10
100
10000
100000000
*/