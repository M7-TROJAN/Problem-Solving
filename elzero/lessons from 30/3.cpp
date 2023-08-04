#include <iostream>
using namespace std;

int main()
{
  int num;

  label:
  cout << "Please Type A Number Between 0 And 150\n";
  cin >> num;
  if(num > 150)
  {
    cout << "the number should be Between 0 And 150 \n";
    goto label;
  }

  if (num < 10)
    cout << "00" <<num <<"\n";
  else if ( num > 10 && num < 100)
    cout << 0 << num << "\n";
  else
    cout << num << "\n";
  
  cout << "Good bye\n";

  // If Number Smaller Than 10 "Example 5" Output Will Be => 005
  // If Number Larger Than 10 And Smaller Than 100 "Example 59" Output Will Be => 059
  // If Number Larger Than 100 "Example 115" Output Will Be => 115
  return 0;
}