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

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev=NULL;
        ListNode *curr=head;

        while(curr)
        {
            ListNode *newtemp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newtemp;
        }
        return prev;

    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode *slow=head;
        ListNode *fast=head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

        }

        ListNode *secondhalf=reverse(slow);
        ListNode *firsthalf=head;

        ListNode *temp=secondhalf;
        while(temp)
        {
            if(firsthalf->val != temp->val)
            return false;
             firsthalf = firsthalf->next;
            temp = temp->next;
        }
        return true;

    }
};