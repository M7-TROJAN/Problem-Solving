# String Concatenation in C++

This C++ code demonstrates a powerful way to concatenate multiple strings using a variadic template function. It offers a recursive concatenation method to join various string inputs together.

## How it Works

The code includes two functions:
- `concat()` - serves as the base case for the recursive function to concatenate strings.
- `concat(const std::string &first, const Args &...args)` - a recursive function using variadic templates that concatenates strings.

The `concat` function uses a recursive approach to join strings, starting with a base case that returns an empty string. It then appends the provided strings together in a recursive manner, producing the final concatenated string.

### Usage

```cpp
#include <iostream>
#include <string>

// Base case of the recursive function to concatenate strings
std::string concat() {
    return ""; // Base case: returns an empty string
}

// Recursive function to concatenate strings
template <typename ... Args>
std::string concat(const std::string &first, const Args &...args) {
    // Check if the provided argument is a string
    static_assert(std::conjunction_v<std::is_convertible<Args, std::string>...>,
                  "All arguments must be of type std::string");

    return first + concat(args...);
}

int main() {
    // Concatenating multiple strings
    std::string result = concat("Hello, ", "world", "!", " I am", " Mahmoud ", "and",
                                " This", " is", " a", " concatenated", " string.");

    std::cout << "Result: " << result << std::endl;
    return 0;
}

```

> **Note**: Ensure that all arguments passed to the 'concat' function are of type std::string.
The result will be the concatenated string printed to the console.

Feel free to use and modify this code as needed. If you find any issues or have suggestions for improvement, please don't hesitate to contribute or open an issue.

## Author

- Mahmoud Mohamed
- Email: mahmoud.abdalaziz@outlook.com
- LinkedIn: [Mahmoud Mohamed Abdalaziz](https://www.linkedin.com/in/mahmoud-mohamed-abd/)

Happy learning and coding! 🚀