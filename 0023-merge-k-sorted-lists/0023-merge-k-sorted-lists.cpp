class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        // push heads
        for (auto node : lists) {
            if (node)
                pq.push({node->val, node});
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();

            tail->next = node;
            tail = node;

            if (node->next)
                pq.push({node->next->val, node->next});
        }

        return dummy.next;
    }
};
