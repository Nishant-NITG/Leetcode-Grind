class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head || k == 1)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;

        while(true)
        {
            // Step 1: Check if k nodes exist
            ListNode* kth = prevGroupEnd;
            for(int i = 0; i < k && kth; i++)
                kth = kth->next;

            if(!kth) break;

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroup = kth->next;

            // Step 2: Reverse k nodes
            ListNode* prev = nextGroup;
            ListNode* curr = groupStart;

            while(curr != nextGroup)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Step 3: Connect reversed group
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }
};