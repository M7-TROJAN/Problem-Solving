#include "Test.h"

bool tryAgain()
{
    char choice = 'y';
    std::cout << "                                            Do You Want To Try Again (y/n)?: ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        system("color 0f");
        system("cls");
        return true;
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        system("color 0f");
        return false;
    }
}

int getTestInfo()
{
    return readNumber_From_To(1, 100, "How Many Questions Do You Want To Answer (from 1 to 100)?:\n");
}

void startTest()
{
    int numberOfQuestions = getTestInfo();
    system("cls");
    Test test(numberOfQuestions);
    test.start();
}
int main()
{
    srand((unsigned)time(NULL));
    do
    {
        startTest();
    } while (tryAgain());
}
