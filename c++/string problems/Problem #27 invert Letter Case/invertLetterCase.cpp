#include <iostream>
char get_char(std::string message = "")
{
    char letter = ' ';
    std::cout << message;
    std::cin >> letter;
    return letter;
}

char invertLetterCase(char ch)
{
    return std::isupper(ch) ? std::tolower(ch) : std::toupper(ch);
}

int main()
{
    char ch = get_char("Please enter a character: ");
    std::cout << "Character after inverting case: ";
    ch = invertLetterCase(ch);
    std::cout << ch << std::endl;

    return 0;
}
