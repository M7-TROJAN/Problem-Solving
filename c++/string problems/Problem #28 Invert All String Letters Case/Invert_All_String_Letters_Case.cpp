#include <iostream>
#include <string>

std::string get_string(const std::string &message = "")
{
    std::string str;
    std::cout << message;
    std::getline(std::cin, str);
    return str;
}
char invertLetterCase(char ch)
{
    return std::isupper(ch) ? std::tolower(ch) : std::toupper(ch);
}

std::string InvertAllStringLettersCase(const std::string &Sentence)
{
    std::string invertingSentence = Sentence;

    for (char & c : invertingSentence)
    {
        c = invertLetterCase(c);
    }
    return invertingSentence;
}
int main()
{
    std::string Sentence = get_string("Enter a sentence: ");
    std::cout << "sentence after inverting case: ";
    Sentence = InvertAllStringLettersCase(Sentence);
    std::cout << Sentence << std::endl;

    return 0;
}
