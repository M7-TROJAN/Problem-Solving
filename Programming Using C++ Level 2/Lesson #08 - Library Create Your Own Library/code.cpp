#include <iostream>
#include "myLip.h"

int main(void)
{
    std::string name = inputs::get_string("Enter Your Name: ");
    int age = inputs::get_int("Enter Your Age: ");
    char Gender = inputs::get_char("Enter Your Gender: ");

    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Gender: " << Gender << std::endl;
}