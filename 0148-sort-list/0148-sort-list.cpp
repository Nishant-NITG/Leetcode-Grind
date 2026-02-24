class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 != NULL && l2 != NULL) {

            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        if (l1 != NULL)
            tail->next = l1;
        else
            tail->next = l2;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL;  // split

        // Recursively sort halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Merge sorted halves
        return merge(left, right);
    }
};