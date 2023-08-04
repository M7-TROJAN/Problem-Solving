#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
  for(int i = 0 ; i < 20 ; i+=2)
    cout << i << " ";
  
  cout << "\n";
  
  int i = 0;
  while(i < 20)
  {
    cout << i << " ";
    i+=2;
  }

}

// Output Needed 0 2 4 6 8 14 16 18