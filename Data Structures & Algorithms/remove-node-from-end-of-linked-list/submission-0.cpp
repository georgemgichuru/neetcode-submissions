/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node handles edge cases (e.g., removing the head node)
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = dummy;

        // Move right pointer n + 1 steps ahead to create the gap
        for (int i = 0; i <= n; ++i) {
            right = right->next;
        }

        // Move both pointers until right reaches the end of the list
        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }

        // left is now positioned immediately before the node to remove
        ListNode* nodeToDelete = left->next;
        left->next = left->next->next; // Bypass the target node

        // Explicitly free the memory of the removed node
        delete nodeToDelete;
        
        // Save the new head and clean up the dummy node
        ListNode* newHead = dummy->next;
        delete dummy; 
        
        return newHead;
    }
};