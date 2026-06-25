class Solution {
    // Custom comparator for the min-heap
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // Push the head of each non-empty list into the priority queue
        for (ListNode* head : lists) {
            if (head) {
                pq.push(head);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Continuously extract the smallest node and push its next node
        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            
            if (tail->next) {
                pq.push(tail->next);
            }
        }
        
        return dummy.next;
    }
};