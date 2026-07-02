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
    
    ListNode* partition(ListNode* head, int x) {
        ListNode* before1 = new ListNode(0);
        ListNode* after1 = new ListNode (0);
        

        ListNode* before = before1;
        ListNode* after = after1;

        ListNode* temp = head;


        while(temp != NULL){
            if(temp -> val < x){
                before -> next = temp;
                before = before -> next;
            }
            else{
                after -> next = temp;
                after = after->next;
            }
            temp = temp -> next;
        }
        after -> next = NULL;
        before -> next = after1 -> next;
        return before1 -> next;

    }
};