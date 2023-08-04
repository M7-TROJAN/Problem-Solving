#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
int main()
{
  for(int i = 0 ; i <= 10 ; i++)
    cout << i << " ";
  
  printf("\n");
//.................................................................

  int i = 0;
  do
  {
    cout << i << " ";
    i++;
  } while (i <= 10);
  
  printf("\n");
//....................................................................

  int x = 0;
  while (x <= 10)
  {
    cout << x << " ";
    x++;
  }
  cout << "\n";
  
}