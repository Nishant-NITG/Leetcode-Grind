/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         int count = 0;
        ListNode* temp = head;
        
        // Count the number of nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        count = count - n;
        
        // If removing the first node
        if (count == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

        return head; 

    
}
};