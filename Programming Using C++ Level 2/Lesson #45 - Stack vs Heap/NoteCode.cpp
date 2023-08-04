#include <iostream>
using namespace std;

int main()
{
    // Stack: Memory region for automatic memory management
    int stackVariable = 5; // Stored on the stack
    // The stack is organized as Last-In-First-Out (LIFO)

    // Heap: Memory region for dynamic memory allocation
    int* heapVariable = new int; // Dynamically allocated on the heap
    // The heap provides more flexible memory storage compared to the stack

    // Stack vs. Heap
    // - The stack is used for storing local variables and function call information
    // - The stack memory is automatically managed by the compiler
    // - The stack has a predetermined and limited size
    // - Memory allocation and deallocation on the stack is faster

    // - The heap is used for dynamic memory allocation
    // - Memory on the heap is explicitly allocated and deallocated by the programmer
    // - The heap provides more flexibility and allows dynamic memory allocation
    // - Objects created with "new" and arrays created with "new[]" are stored on the heap
    // - The size of the heap can be increased dynamically as needed

    // Cleaning up
    delete heapVariable; // Deallocate memory on the heap
    heapVariable = nullptr; // Set the pointer to nullptr for safety

    return 0;
}

/*
In computer programming, the terms "heap" and "stack" refer to two different regions of memory used for different purposes:
Stack:
The stack is a region of memory used for automatic memory management.
It is organized in a last-in-first-out (LIFO) manner.
The stack is typically used for storing local variables, function call information, and return addresses.
Memory allocation and deallocation on the stack is done automatically by the compiler.
The size of the stack is usually fixed and limited.
Stack memory is faster to allocate and deallocate compared to heap memory.

Heap:
The heap is a region of memory used for dynamic memory allocation.
It is a more flexible memory storage compared to the stack.
Memory allocation and deallocation on the heap are done explicitly by the programmer using functions like new and delete in C++.
The heap is used for storing dynamically allocated objects, such as objects created with new or arrays created with new[].
Memory on the heap can be allocated and deallocated in any order, and the programmer is responsible for managing it.
The size of the heap is typically larger and can grow dynamically as needed.
Heap memory allocation can be slower than stack memory allocation due to the dynamic nature of allocation.

In summary, the stack is used for automatic memory management and storing local variables,
while the heap is used for dynamic memory allocation and storing dynamically allocated objects.
The stack is faster but has a limited size, while the heap is more flexible but requires explicit management by the programmer.
*/
