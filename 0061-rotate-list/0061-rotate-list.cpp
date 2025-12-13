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
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0) return head;

        // Compute the length of the linked list
        int length = 1;  // Start from 1 since we start at head
        ListNode *tail = head;

        while (tail->next != NULL) {  // Find the last node
            tail = tail->next;
            length++;
        }

        // Adjust k to avoid unnecessary full rotations
        k = k % length;
        if (k == 0) return head;

        // Connect last node to head to form a circular list
        tail->next = head;
        ListNode *newtail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newtail = newtail->next;
        }

        // Break the cycle and set new head
        ListNode *newhead = newtail->next;
        newtail->next = NULL;

        return newhead;

    }
};