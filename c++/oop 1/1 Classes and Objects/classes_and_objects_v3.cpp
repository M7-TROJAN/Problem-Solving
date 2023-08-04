#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(const std::string& personName, int personAge)
        : name(personName), age(personAge) {}

    // Member function
    void displayInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Creating objects of the Person class
    Person person1("Mahmoud", 25);
    Person person2("Rahma", 23);

    // Accessing member functions of objects
    person1.displayInfo();
    person2.displayInfo();

    return 0;
}

// This example demonstrates the concept of a class and objects in C++. The class serves as a blueprint 
// that defines the properties and behaviors of objects. Objects are instances of the class,
// and they can be created to store and manipulate data using the member functions defined within the class.