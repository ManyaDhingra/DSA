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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>> pq;


            for (auto node : lists) {
            if (node) pq.push({node->val, node});
        }

        if (pq.empty()) return nullptr;

        // first node initializes head
        auto [val, head] = pq.top();
        pq.pop();

        if (head->next) {
            pq.push({head->next->val, head->next});
        }
        ListNode* tail = head;

        while (!pq.empty()) {
            auto [v, node] = pq.top();
            pq.pop();

            tail->next = node;
            tail = node;

            if (node->next) {
                pq.push({node->next->val, node->next});
            }
        }

        return head;

        
    }
};