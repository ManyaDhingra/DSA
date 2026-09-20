/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int flag = 0;
        unordered_map<ListNode*, int> p;
        while(p1 != NULL){
            p[p1] = 1;
            p1 = p1 -> next;
        }

        while(p2 != NULL){
            if(p[p2] == 1){
                return p2;
            }
            else{
                p2 = p2 -> next;
            }
        }
        return NULL;
    }
};