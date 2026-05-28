class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
    
        ListNode* first = dummy;
        ListNode* second = dummy;
    
        // Move secondPtr n spaces ahead
        for (int i = 0; i < n; i++) {
          second= second->next;
        }
    
        // Move both now, until the next of secondPtr is null
        while(second->next != NULL) {
          first = first->next;
          second = second->next;
        }
    
        // We now have to remove the node next of firstPtr
        first->next = first->next->next;
    
        return dummy->next;
        }
    };
    