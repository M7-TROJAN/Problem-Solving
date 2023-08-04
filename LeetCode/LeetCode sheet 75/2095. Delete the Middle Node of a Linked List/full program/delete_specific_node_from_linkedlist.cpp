#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteNode(ListNode* head, const int &targetValue) {
    // Check if the linked list is empty
    if (head == nullptr)
        return nullptr;

    // If the target node is the head, update the head to the next node and delete the original head
    if (head->val == targetValue) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Traverse the linked list to find the target node and keep track of the previous node
    ListNode* prev = head;
    ListNode* current = head->next;
    while (current != nullptr && current->val != targetValue) {
        prev = current;
        current = current->next;
    }

    // If the target node is found, remove it from the linked list
    if (current != nullptr) {
        prev->next = current->next;
        delete current;
    }

    // Return the head of the modified linked list
    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original Linked List: ";
    printList(head);

    // Delete node with value 3
    int targetValue = 3;
    head = deleteNode(head, targetValue);
    std::cout << "Linked List after deleting node with value " << targetValue << ": ";
    printList(head);

    // Delete node with value 1 (head node)
    targetValue = 1;
    head = deleteNode(head, targetValue);
    std::cout << "Linked List after deleting node with value " << targetValue << ": ";
    printList(head);

    // Delete node with value 5 (last node)
    targetValue = 5;
    head = deleteNode(head, targetValue);
    std::cout << "Linked List after deleting node with value " << targetValue << ": ";
    printList(head);

    // Delete node with value 10 (non-existent node)
    targetValue = 10;
    head = deleteNode(head, targetValue);
    std::cout << "Linked List after deleting node with value " << targetValue << ": ";
    printList(head);

    // Clean up memory (freeing allocated nodes)
    ListNode* temp = nullptr;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
