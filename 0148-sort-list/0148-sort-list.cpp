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
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next ;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;

    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        if (l1 == NULL){
            return l2;
        }
        if (l2 == NULL){
            return l1;
        }
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        while(l1 != NULL && l2 != NULL){
            if(l1-> val < l2->val){
                temp ->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp ->next = l2;
                temp = l2;
                l2 = l2 ->next;
            }
        }
        while (l1 != NULL){
            temp ->next = l1;
            temp = l1;
            l1 = l1->next;

        }
        while (l2 != NULL){
            temp ->next = l2;
            temp = l2;
            l2 = l2 ->next;
        }
        ans = ans -> next;
        return ans;
       
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        // ll separation
        ListNode* mid = middle(head);

        ListNode* start = head;
        ListNode* midStart = mid -> next;
        mid -> next = NULL;

        //recurrsive call
        start = sortList(start);
        midStart = sortList(midStart);

        // merge both
        ListNode * ans = merge(start, midStart);
        return ans;


        
    }
};