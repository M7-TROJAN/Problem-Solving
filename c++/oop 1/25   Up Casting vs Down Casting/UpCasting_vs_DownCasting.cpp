#include <iostream>
using namespace std;
class Animal {
public:
    void makeSound() {
        cout << "Animal makes a sound." << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        cout << "Dog barks." << endl;
    }

    void fetch() {
        cout << "Dog fetches the ball." << endl;
    }
};

int main() {
    Animal* animalPtr = new Dog();
    animalPtr->makeSound();  // Output: Dog barks. (Polymorphism: dynamic binding based on actual object type)

    // Downcasting: Converting Animal to Dog (explicit and potentially unsafe)
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);
    if (dogPtr != nullptr) {
        dogPtr->fetch();  // Output: Dog fetches the ball.
    } else {
        cout << "Cannot downcast to Dog." << endl;
    }

    // Remember to delete the allocated memory (not shown in this example)
    delete animalPtr;
}
