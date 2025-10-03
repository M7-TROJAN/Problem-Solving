#include <iostream>
#include "linkedList.h"

int main() {
    LinkedList<int> list(1,2,3,4,5,6,7,8,9,10);
    cout << "is list empty?: " << (list.isEmpty()? "true" : "false") << endl;
    list.printList();
    cout << "length: " << list.length() << endl;
    list.insertAtBeginning(100);
    list.insertAtEnd(11);
    list.insertAtEnd(12);
    list.insertAtEnd(13);
    list.insertAtEnd(14);
    list.insertAtEnd(15);
    list.insertAtEnd(16);
    list.printList();
    cout << "length: " << list.length() << endl;
    list.Clear();
    cout << "is list empty?: " << (list.isEmpty()? "true" : "false") << endl;
    return 0;
}