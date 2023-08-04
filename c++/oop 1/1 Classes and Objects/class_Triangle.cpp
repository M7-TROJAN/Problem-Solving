#include <iostream>

class Triangle
{
private:
    double base;
    double height;

public:
    Triangle(double b = 0.0, double h = 0.0) : base(b), height(h) {}

    void setBase(double b)
    {
        base = b;
    }

    void setHeight(double h)
    {
        height = h;
    }

    double getArea() const
    {
        return 0.5 * base * height;
    }

    void print() const
    {
        std::cout << "Base: " << base << "\n"
                  << "Height: " << height << "\n"
                  << "Area: " << getArea() << "\n";
    }
};

int main()
{
    Triangle tr(5, 10);
    std::cout << "\ntr1:\n";
    tr.print(); // 5  10  25

    tr.setBase(8.5);
    tr.setHeight(12.3);
    std::cout << "\ntr1:\n";
    tr.print(); // 8.5   12.3   52.275

    std::cout << "\n=======================\n\n";

    Triangle tr2;

    std::cout << "\ntr2:\n";
    tr2.print(); // 0  0  0

    tr2.setBase(10);
    tr2.setHeight(7.5);

    std::cout << "\ntr2:\n";
    tr2.print(); // 10    7.5    37.5
    return 0;
}



/*

In the code `Triangle(double b = 0.0, double h = 0.0) : base(b), height(h) {}`
it defines a constructor for the `Triangle` class with two parameters `b` and `h` of type `double`.
These parameters have default values of `0.0` in case no values are provided when creating a `Triangle` object.

The part `: base(b), height(h)` is called the member initializer list.
It initializes the data members `base` and `height` with the provided values `b` and `h`, respectively.
This is done before the body of the constructor is executed.

So, when you create a `Triangle` object, you have the option to pass values for `base` and `height`,
or if no values are provided, the constructor will use the default values of `0.0` for both `base` and `height`.

Here's an example usage of the constructor:

Triangle tr;  // Triangle object with base = 0.0 and height = 0.0
Triangle tr2(3.5, 7.2);  // Triangle object with base = 3.5 and height = 7.2

*/