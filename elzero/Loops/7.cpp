#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
  for (int i = 2 ; i <= 128 ; i*=2)
    cout << i << " ";

  cout << "\n";

  int i = 2;
  while(i <= 128)
  {
    cout << i << " ";
    i*=2;
  }

}
// Output Needed 2 4 8 16 32 64 128