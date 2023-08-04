#include <iostream>
using namespace std;

class MyClass {
public:
    // Static method that returns a constant value of 10.
    static int staticMethod() {
        // Static method does not have access to instance-specific member variables (non-static variables).
        // It can only access static member variables (class-level variables).
        // It does not have access to the 'this' pointer since there is no specific instance associated with it.
        return 10;
    }

    // Non-static method that returns a constant value of 20.
    int nonStaticMethod() {
        // Non-static method (instance-specific method) has access to both static and non-static member variables.
        // It can access the 'this' pointer, which points to the specific instance calling the method.
        return 20;
    }
};

int main() {
    // Call the static method directly through the class name (no object creation required).
    cout << "Static method result: " << MyClass::staticMethod() << endl;

    // Static methods can also be called through objects, but it's not recommended, as they are not instance-specific.
    MyClass obj1;
    cout << "Static method result through object: " << obj1.staticMethod() << endl;

    // Call the non-static method through an object.
    cout << "Non-static method result: " << obj1.nonStaticMethod() << endl;

    return 0;
}

/*
Explanation:

1. In the example, we have a class 'MyClass' with two methods: 'staticMethod()' and 'nonStaticMethod()'.

2. The 'staticMethod()' is a static method, indicated by the 'static' keyword in its declaration. It does not operate on any specific object of the class
and can be called directly through the class name 'MyClass::staticMethod()'.

3. Static methods cannot access instance-specific member variables (non-static variables) or the 'this' pointer since they are not associated with any specific instance.

4. The 'nonStaticMethod()' is a non-static method, also known as an instance-specific method.
It can be called through objects of the class, such as 'obj1.nonStaticMethod()'.

5. Non-static methods can access both static and non-static member variables and have access to the 'this' pointer, which points to the specific instance calling the method.

6. In the 'main()' function, we demonstrate calling the static method both directly through the class name 'MyClass::staticMethod()'
and through an object 'obj1.staticMethod()'.
However, it's important to note that calling static methods through objects is not recommended since they are not instance-specific.

When to use static methods:
- Use static methods when the functionality does not depend on any specific object's state and can be defined at the class level.
- Use static methods for utility functions or operations that are relevant to the entire class and do not require access to instance-specific data.

When not to use static methods:
- Avoid using static methods when the functionality requires access to instance-specific data or when the method's behavior may vary for different instances of the class.
In such cases, use non-static methods.
*/
