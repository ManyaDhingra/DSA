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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* agla;

        while(curr != NULL){
            agla = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = agla;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        
        ListNode* curr = head;
        int maxi = curr -> val;
        while(curr && curr -> next){
            if(curr -> next -> val < maxi){
                curr -> next = curr -> next -> next;
            }
            else{
                curr = curr -> next;
                maxi = curr -> val;
            }
        }
        return reverse(head);
    }
};