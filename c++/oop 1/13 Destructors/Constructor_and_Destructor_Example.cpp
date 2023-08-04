// Constructor and Destructor Example

#include <iostream>
using namespace std;

class Rectangle {
private:
    int* _Length; // Pointer to store the length of the rectangle
    int* _Width;  // Pointer to store the width of the rectangle

public:
    // Constructor for the Rectangle class that takes the length and width as arguments
    Rectangle(int length, int width) {
        _Length = new int; // Dynamically allocate memory for _Length on the heap
        _Width = new int;  // Dynamically allocate memory for _Width on the heap

        *_Length = length; // Assign the value of 'length' to the memory location pointed by _Length
        *_Width = width;   // Assign the value of 'width' to the memory location pointed by _Width
        cout << "Hi I'm Constructor Object has Created.\n"; // Display a message indicating that the object has been created
    }

    // Method to calculate the area of the rectangle
    double getArea() {
        return (*_Length) * (*_Width); // Calculate and return the area by dereferencing _Length and _Width pointers
    }

    // Destructor for the Rectangle class
    ~Rectangle() {
        delete _Length; // Deallocate the memory used for _Length
        delete _Width;  // Deallocate the memory used for _Width
        cout << "Hi I'm Destructor Object has destroyed.\n"; // Display a message indicating that the object has been destroyed
    }
};

int main() {
    // Create an instance of the Rectangle class named 'rec' with length 4 and width 7
    Rectangle rec(4, 7);

    // Calculate the area of the rectangle using the getArea() method and display the result
    cout << "Area: " << rec.getArea() << endl;
}
