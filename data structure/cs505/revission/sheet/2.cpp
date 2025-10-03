/*

4. Write a class Student which contains private members "char* Stud-name, int Stud-ID, float Total , float Perc". 
    Perc will be calculated using this formula for each student " Perc = Total / 500 * 100. 
    The class has only two public methods , "GetStudDetails, PutStudDetails". 
    After creating the class, use it to read and print multiple student details using linked list of objects.
*/

#include <iostream>


template<typename T>
struct Node {
    T data; 
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
void Arrange(Node<T>*& head) {
    if (!head || !head->next) {
        return; // If the list is empty or has only one node, no need to sort.
    }

    bool swapped;
    do {
        swapped = false;
        Node<T>* current = head;

        while (current->next) {
            if (current->data > current->next->data) {
                // Swap the data of current node and next node
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

template<typename T>
Node<T>* Reverse(Node<T>* list) {
    if (!list || !list->next) {
        return list; // Return as-is if the list is empty or has only one node.
    }

    Node<T>* current = list;
    Node<T>* reversedList = nullptr;

    while (current) {
        Node<T>* nextNode = current->next; // Store the next node.
        current->next = reversedList;     // Reverse the link.
        reversedList = current;           // Move the head of the reversed list.
        current = nextNode;               // Advance to the next node.
    }
    return reversedList;
}

template<typename T>
Node<T>* RearrangeEvenOdd(Node<T>* head) {
    if (!head || !head->next) {
        return head; // No need to rearrange if list is empty or has one node.
    }

    Node<T>* evenHead = nullptr; // Start of even numbers
    Node<T>* evenTail = nullptr; // End of even numbers
    Node<T>* oddHead = nullptr;  // Start of odd numbers
    Node<T>* oddTail = nullptr;  // End of odd numbers
    Node<T>* current = head;

    while (current) {
        if (current->data % 2 == 0) { // Check if the number is even
            if (!evenHead) {
                evenHead = evenTail = current; // First even node
            } else {
                evenTail->next = current; // Add to even list
                evenTail = evenTail->next;
            }
        } else { // Odd number
            if (!oddHead) {
                oddHead = oddTail = current; // First odd node
            } else {
                oddTail->next = current; // Add to odd list
                oddTail = oddTail->next;
            }
        }
        current = current->next; // Move to the next node
    }

    if (evenTail) {
        evenTail->next = oddHead; // Connect even list to odd list
    }
    if (oddTail) {
        oddTail->next = nullptr; // End of the odd list
    }

    return evenHead ? evenHead : oddHead; // Return the head of the new list
}


template<typename T>
void PrintList(Node<T>* head) {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}

template<typename T>
void free(Node<T>* head)
{
    while (head) {
        Node<int>* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    Node<int>* head = new Node<int>(1);
    head->next = new Node<int>(2);
    head->next->next = new Node<int>(3);
    head->next->next->next = new Node<int>(4);

    std::cout << "Original list:" << std::endl;
    PrintList(head);

    Node<int>* reversedHead = Reverse(head);

    std::cout << "Reversed list:" << std::endl;
    PrintList(reversedHead);

    Arrange(reversedHead);

    free(reversedHead);

    Node<int>* list = new Node<int>(5);
    list->next = new Node<int>(2);
    list->next->next = new Node<int>(3);
    list->next->next->next = new Node<int>(4);
    list->next->next->next->next = new Node<int>(20);
    std::cout << "Original list:" << std::endl;
    PrintList(list);

    Node<int>* rearrangedList = RearrangeEvenOdd(list);

    std::cout << "rearrangedList" << std::endl;
    PrintList(rearrangedList);

    free(rearrangedList);

    return 0;
}