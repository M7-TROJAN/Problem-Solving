#include <iostream>
using namespace std;
int main()
{
  // example 1:

  int numbers[] = {10, 20, -20, 13, 30, -30, 40};
  // from the array (numbers) count only positive numbers and even numbers
  int numbers_size = sizeof(numbers) / sizeof(numbers[0]);
  int result = 0;
  for (int i = 0; i < numbers_size; i++)
  {
    if (numbers[i] > 0 && numbers[i] % 2 == 0)
      result += numbers[i];
  }
  cout << "result is " << result << endl;

  //...........................................................................................

  // example 2:

  // guess the number

  srand(time(NULL));
  int randomNumber = rand() % (10 - 1 + 1) + 1;
  int guessNumber = 0;
  int guessTries = 1;
  cout << "Please Guess The Number Between 1 & 10\n";
  cout << "Remember You Only Have 3 Tries\n";

  while (true)
  {
    cin >> guessNumber;
    if (guessNumber == randomNumber)
    {
      cout << "Great You Are Right :)\n";
      break;
    }
    if (guessTries >= 3)
    {
      cout << "Sorry, Your tries Are Finished :(\n";
      cout << "The Random Number Was " << randomNumber << "\n";
      break;
    }
    cout << "Try Again\n";
    guessTries++;
  }

  //...........................................................................................

  // example 3:
  // Reversed Elements From User

  int vals[5];
  int n = sizeof(vals) / sizeof(vals[0]);
  cout << "Type Five Numbers to Reverse\n";
  for (int i = 0; i < n; i++)
    cin >> vals[(n - 1) - i];

  cout << "Your Elements After Reversing is\n";
  for (int i = 0; i < n; i++)
    cout << vals[i] << "\n";
}
