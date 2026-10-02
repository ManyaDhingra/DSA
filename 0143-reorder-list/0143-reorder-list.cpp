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
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return ;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* l2 = slow->next;
        slow ->  next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = l2;
        while(curr != NULL){
            ListNode* agla = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = agla;
        }
        l2 = prev;
         ListNode* l1 = head;

        while (l2!= NULL) {
            ListNode* firstNext = l1->next;
            ListNode* secondNext = l2->next;

            l1->next = l2;
            l2->next = firstNext;

            l1 = firstNext;
            l2 = secondNext;
        }
    }
};