#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Check if the linked list has 0 or 1 nodes
        if (head == nullptr || head->next == nullptr)
            return head; // There is no middle node in a linked list with 0 or 1 nodes

        // Initialize two pointers, slow and fast, to traverse the list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // Pointer to keep track of the previous node

        // Traverse the list using two pointers to find the middle node
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;          // Update the previous pointer
            slow = slow->next;    // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        // simulation:
        // linked list = 1   2   3   4   5   6  7
        // prev                  |
        // slow                      |
        // fast                                  |    now fast pointer reaches the end of the list so the slow pointer now pointing to the middle node and the loop will stop

        // Remove the middle node pointed by 'slow'
        prev->next = slow->next; // Skip the middle node

        // Deallocate the memory occupied by the middle node
        delete slow;

        return head; // Return the head of the modified linked list
    }
};

int main() 
{
    // Create a sample linked list: 1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution solution;
    ListNode* modifiedHead = solution.deleteMiddle(head);

    // Print the modified linked list: 1 -> 3 -> 4 -> 1 -> 2 -> 6
    ListNode* current = modifiedHead;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;

    // Deallocate memory used by the linked list
    current = modifiedHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

/*
To delete the middle node from the linked list, we need to traverse the list to find the middle node, then remove it from the list. 
To achieve this, we can use the two-pointer: one slow pointer that moves one step at a time 
and one fast pointer that moves two steps at a time. When the fast pointer reaches the end of the list, the slow pointer will be pointing to the middle node.
*/

/*
Explanation:
The deleteMiddle function takes the head of the linked list as input and returns the head of the modified linked list after removing the middle node.
It first checks if the linked list has 0 or 1 nodes. If so, it returns nullptr since there is no middle node to delete. 
Otherwise, it initializes two pointers, slow and fast, to traverse the list. 
When the fast pointer reaches the end of the list, the slow pointer will be pointing to the middle node.

After finding the middle node, the function removes it from the list by updating the next pointer of the previous node (prev) to skip the middle node.

Finally, the memory occupied by the middle node is deallocated using the delete operator, and the modified head is returned.
*/