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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            size++;
            temp = temp -> next;
        }
        size = size - n;
        if(size == 0){
            head = head -> next;
            return head;
        }
        ListNode* temp2 = head;
        while(size > 1){
            temp2 = temp2 -> next;
            size--;
        }

        temp2 -> next = temp2 -> next -> next;

        return head;
        
        return head;
    }
};