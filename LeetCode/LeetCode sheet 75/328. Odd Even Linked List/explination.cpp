/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices,
and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    // Step 1: Check if the linked list is empty or has only one node
    if (head == nullptr || head->next == nullptr)
        return head;

    // Step 2: Initialize pointers to separate lists for odd and even nodes
    ListNode* oddHead = head; // Head of the odd-indexed nodes list
    ListNode* evenHead = head->next; // Head of the even-indexed nodes list

    // Step 3: Initialize pointers to traverse the odd and even lists
    ListNode* odd = oddHead; // Pointer to traverse the odd-indexed nodes list
    ListNode* even = evenHead; // Pointer to traverse the even-indexed nodes list

    // Step 4: Traverse the linked list and split nodes into two lists
    while (even != nullptr && even->next != nullptr) {
        // Connect the next node of 'odd' to the next odd-indexed node
        odd->next = even->next;
        // Move 'odd' one step forward
        odd = odd->next;

        // Connect the next node of 'even' to the next even-indexed node
        even->next = odd->next;
        // Move 'even' one step forward
        even = even->next;
    }

    // Step 5: Merge the two lists
    odd->next = evenHead;

    // Step 6: Return the head of the reordered list
    return oddHead;
}

/*

1- First, we check if the linked list is empty or has only one node. If it does, there is no need to reorder the nodes,
so we simply return the head of the list.

2- we initialize two pointers, 'oddHead' and 'evenHead', to point to the heads of two separate lists
one for nodes with odd indices and the other for nodes with even indices. Initially,
'oddHead' points to the first node (the head of the input list), and 'evenHead' points to the second node (if it exists).

3- We will use two more pointers, 'odd' and 'even', to traverse the odd and even lists, respectively. 
Both 'odd' and 'even' start at their respective heads ('odd' starts at 'oddHead', and 'even' starts at 'evenHead').

4- Now, we begin the main loop to split the nodes into two lists. For each iteration, we do the following:

*Connect the next node of 'odd' to the next odd-indexed node (i.e., the node at odd->next->next).
*Move 'odd' one step forward (i.e., odd = odd->next) to get ready for the next iteration.
*Connect the next node of 'even' to the next even-indexed node (i.e., the node at even->next->next).
*Move 'even' one step forward (i.e., even = even->next) to get ready for the next iteration.
By doing this, we effectively split the input linked list into two separate lists:
one with nodes at odd indices and the other with nodes at even indices.

5- After the loop ends, we have two separate lists:
'oddHead' points to the head of the list with odd-indexed nodes, and 'evenHead' points to the head of the list with even-indexed nodes.

6- To get the final reordered list, we need to merge these two lists.
To do that, we connect the last node of the list with odd-indexed nodes to the head of the list with even-indexed nodes.

Finally, we return the head of the merged list ('oddHead'), which is the head of the reordered list 
with all odd-indexed nodes followed by even-indexed nodes.
*/