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
        if (head == nullptr || head->next == nullptr)
            return head; // There is no middle node in a linked list

        // Calculate the length of the linked list
        int ListLength = 0;
        for(ListNode *temp = head; temp != nullptr; temp = temp->next)
        {
            ListLength++;
        }

        // Find the position of the middle node
        int middleNodePosition = ListLength / 2;

        ListNode* middleNode = nullptr;
        ListNode* currentNode = head;

        // Traverse the linked list to find the middle node
        for(int i = 1; i <= middleNodePosition; i++)
        {
            if(i == middleNodePosition)
            {
                // Save the middle node and update the previous node's next pointer to skip the middle node
                middleNode = currentNode->next;
                currentNode->next = middleNode->next;

                // Deallocate the memory occupied by the middle node
                delete middleNode;
                break;
            }
            // Move to the next node in the linked list
            currentNode = currentNode->next;
        }
        // simulation:
        // linked list             1   2   3   4   5   6  7
        // i                               |
        // currentNode                     |
        // currentNode->next                       |
        // middleNode                         |

        // Return the head of the modified linked list
        return head;
    }
};


/*
This algorithm first calculates the length of the linked list by traversing it. Then, it finds the position of the middle node by dividing the length by 2.
The loop then iterates to the middle node position and deletes the middle node by updating the next pointer of the previous node to skip the middle node.
Finally, the memory occupied by the middle node is deallocated, and the head of the modified linked list is returned.
*/