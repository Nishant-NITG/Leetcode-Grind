class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node before the head
        // This simplifies the case when we need to remove the head itself
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize two pointers at dummy
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move fast n steps ahead
        // Creates a gap of n between slow and fast
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the last node
        // When fast->next is NULL, slow is at the node before the target
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Remove the nth node from the end
        // slow->next is the target node
        slow->next = slow->next->next;
        
        // Return the new head (skip dummy)
        return dummy->next;
    }
};