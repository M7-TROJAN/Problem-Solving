
/*
1. Add member functions to the List class with the following specifications:
    A public function . Recursive_List_Size( ) to call a recursive private function to return the size of the list.
*/

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int Recursive_List_Size_Helper(Node<T>* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + Recursive_List_Size_Helper(node->next); // Add 1 and recurse to the next node.
    }
public:
    LinkedList() : head(nullptr){}

    // Variadic Constructor (if you don't know it just ignore it, i put this constructor just for try the code)
    template <typename... Args>
    LinkedList(const T& first, const Args&... args){
        head = nullptr;
        InsertAtEnd(first);
        (InsertAtEnd(args), ...); // Fold Expression
    }

    ~LinkedList() {
        Clear();
    }

    void InsertAtEnd(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void PrintList() const {
        Node<T>* temp = head;
        cout << "{ ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr }\n";
    }

    int Recursive_List_Size() const {
        return Recursive_List_Size_Helper(head);
    }

    void Clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList<int> intList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    cout << "List Size: " << intList.Recursive_List_Size() << "\n"; // List Size: 10

    LinkedList<string> stringList("Mahmoud", "Mohammad", "Ali", "Ahmed", "Adam");
    cout << "List Size: " << stringList.Recursive_List_Size() << "\n"; // List Size: 5
}