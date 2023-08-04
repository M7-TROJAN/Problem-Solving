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
        // Check if the linked list is empty or has only one node
        if (head == nullptr || head->next == nullptr)
            return nullptr; // There is no middle node

        // Initialize two pointers 'slow' and 'fast' to traverse the list
        ListNode* slow = head; // Slow pointer moves one step at a time
        ListNode* fast = head; // Fast pointer moves two steps at a time
        ListNode* prev = nullptr; // Pointer to keep track of the previous node to update next pointers

        // Traverse the linked list using the two-pointer approach
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow; // Update 'prev' to point to the current 'slow' node
            slow = slow->next; // Move 'slow' one step forward
            fast = fast->next->next; // Move 'fast' two steps forward
        }

        // At this point, 'slow' is pointing to the middle node of the linked list

        // Remove the middle node pointed by 'slow'
        if (prev != nullptr)
            prev->next = slow->next; // Update 'next' pointer of 'prev' to skip the middle node

        delete slow; // Free the memory occupied by the middle node

        // Return the head of the modified linked list
        return head;
    }
};

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
If the middle node is the head of the list (i.e., there is no previous node), the head is updated to point to the next node.

Finally, the memory occupied by the middle node is deallocated using the delete operator, and the modified head is returned.
*/