#include <iostream>
using namespace std;

class MyClass {
public:
    int x;             // Instance-specific member variable
    static int count;  // Static member variable shared among all instances

    MyClass() {
        x = 0;         // Initialize instance-specific variable
        count++;       // Increment the static counter for each object created
    }

    static void displayCount() {
        // Static member function can only access static member variables
        // It cannot access instance-specific member variables like 'x'
        cout << "Total objects created: " << count << endl;
    }
};

int MyClass::count = 0; // Initialize the static member variable outside the class

int main() {
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;

    obj1.x = 10; // Set instance-specific variable for obj1
    obj2.x = 20; // Set instance-specific variable for obj2

    // Access static member variable directly using the class name
    cout << "Static member count: " << MyClass::count << endl;

    // Access static member function using the class name
    MyClass::displayCount();

    // Access static member variable using an object (not recommended)
    // obj3.displayCount(); // Avoid accessing static members using objects

    // Access instance-specific variable using objects
    cout << "obj1.x: " << obj1.x << endl;
    cout << "obj2.x: " << obj2.x << endl;
    cout << "obj3.x: " << obj3.x << endl;

    return 0;
}

/*
Explanation:

1. We define a class 'MyClass' with two member variables: 'x' and 'count'.
   The 'x' is an instance-specific member variable, and 'count' is a static member variable shared among all instances.

2. The constructor of the 'MyClass' class initializes the 'x' variable to '0' for each object created and increments the 'count' static variable.

3. We have a static member function 'displayCount' that can only access static member variables.
   It cannot access instance-specific member variables like 'x'.

4. In the 'main' function, we create three objects of the 'MyClass' class: 'obj1', 'obj2', and 'obj3'.

5. We set instance-specific variables 'x' for 'obj1' and 'obj2'.

6. We can access the static member variable 'count' directly using the class name 'MyClass::count'.

7. We can call the static member function 'displayCount' using the class name 'MyClass::displayCount'.

8. It's not recommended to access static member variables using objects (e.g., 'obj3.displayCount()') as they belong to the entire class, not individual objects.

9. We can access instance-specific member variables using objects (e.g., 'obj1.x', 'obj2.x', and 'obj3.x').

When you run this code, it will display the total count of objects created and the values of instance-specific variables for 'obj1', 'obj2', and 'obj3'.
The static member count will be the same for all objects, indicating that it is shared among them.
*/
