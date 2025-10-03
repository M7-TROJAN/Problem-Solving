#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* next;
    explicit Node(const T& data) : data(data), next(nullptr) {}
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
void PrintList(Node<T>* head) {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}

template<typename T>
void PrintListInReverseOrder(Node<T>* list )
{
    if(!list) {
        return;
    }
    PrintListInReverseOrder(list->next);
    cout << list->data << " -> ";
}

template<typename T>
void destroy(Node<T>* list)
{
    if(!list) return;
    while (list)
    {
        Node<T>* temp = list;
        list = list->next;
        delete temp;
    }
}

template <class T>
void Reverse_Ver2(Node<T>*& list) {
    if(!list || !list->next) return;

    Node<T>* current = list;
    Node<T>* nextNode = NULL;
    Node<T>* reversedList = NULL;
    while (current)
    {
        nextNode = current->next;
        current->next = reversedList;
        reversedList = current;
        current = nextNode;
    }
    list = reversedList;
}

template<typename T>
void RearrangeEvenOdd_Ver2(Node<T>*& head) {
    if (!head || !head->next) {
        return; // No need to rearrange if the list is empty or has one node.
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

    // Properly terminate the lists to avoid dangling pointers
    if (evenTail) {
        evenTail->next = oddHead; // Connect even list to odd list
    }
    if (oddTail) {
        oddTail->next = nullptr; // End the odd list properly
    }

    head = evenHead ? evenHead : oddHead; // Return the head of the new list
}

// write a function Append () to received two lists ( L1, L2 ) and append L2 to the end of L1 
// returning the result in a new list ( L) without changing the original lists.
template <class T>
Node<T>* Append(Node<T>* L1, Node<T>* L2) {
    // create a new empty list
    Node<T>* newList = nullptr; // the head of the new lit
    Node<T>* tail = nullptr;    // the last Node in the new list

    // copy l1 elements to the new list.
    Node<T>* current = L1;
    while (current != nullptr) {
        Node<T>* newNode = new Node<T>(current->data);
        if (newList == nullptr) {
            newList = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        current = current->next;
    }

   // copy l2 elements to the new list.
    current = L2;
    while (current != nullptr) {
        Node<T>* newNode = new Node<T>(current->data);
        if (newList == nullptr) {
            newList = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        current = current->next;
    }

    return newList;
}

// Write a function Count() to count how many times a given number occurs in the given list. 
// The function takes two arguments; the list and the number you want to count.
template <typename T>
int Count(Node<T>*& list, const T& value)
{
    int result = 0;
    Node<T>* temp = list;
    while (temp)
    {
        if(temp->data == value)
            result++;
        temp = temp->next;
    }
    return result;
}

int main() {
    // Create a sample linked list
    Node<int>* head = new Node<int>(6);
    head->next = new Node<int>(1);
    head->next->next = new Node<int>(5);
    head->next->next->next = new Node<int>(3);
    head->next->next->next->next = new Node<int>(2);
    head->next->next->next->next->next = new Node<int>(4);
    head->next->next->next->next->next->next = new Node<int>(6);

    cout << "Original List:" << endl;
    PrintList(head);

    // Reverse_Ver2
    Reverse_Ver2(head);
    cout << "Reversed List:" << endl;
    PrintList(head);

    // RearrangeEvenOdd_Ver2
    RearrangeEvenOdd_Ver2(head);
    cout << "Rearranged Even-Odd List:" << endl;
    PrintList(head);

    // Arrange (Sort the list)
    Arrange(head);
    cout << "Sorted List:" << endl;
    PrintList(head);

    // Print list in reverse order without modifying it
    cout << "List in Reverse Order (Print only):" << endl;
    PrintListInReverseOrder(head);
    cout << "null" << endl;

    Node<int>* list = Append(head, head);
    PrintList(head);
    PrintList(list);

    cout << Count<int>(head, 6) << endl;

    // Clean up memory
    destroy(head);
    destroy(list);
    return 0;
}

// 2. Receive a list and to return the sum of data stored in the list.

template<class T>
int sum(Node<T>* list)
{
    Node<T>* temp = list;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}