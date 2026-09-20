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
    ListNode *detectCycle(ListNode *head) {

        ListNode* p1 = head;
        unordered_map<ListNode* , int> mp;
        while(p1 != NULL){
           
            if(mp[p1] == 1){
                return p1;
            }
            else{
                mp[p1] = 1;
                p1 = p1-> next;
            }
        }
        return NULL;
        
    }
};