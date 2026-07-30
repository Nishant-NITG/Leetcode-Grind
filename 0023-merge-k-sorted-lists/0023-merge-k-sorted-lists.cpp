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

// Comparator class for Min Heap
class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min Heap
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Put the first node of every list into the heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        // Dummy node
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            // Get the smallest node
            ListNode* smallest = pq.top();
            pq.pop();

            // Add it to the answer
            tail->next = smallest;
            tail = tail->next;

            // Push the next node of the same list
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};