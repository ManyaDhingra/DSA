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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pre = list1;

        for(int i = 0 ; i < a-1 ; i++){
            pre = pre -> next;
        }

        ListNode* after = pre;

        for(int i = a-1 ; i < b ; i++){
            after = after -> next;
        }

        after = after->next;

        pre->next = list2;

        while(list2 -> next){
            list2 = list2 -> next;
        }

        list2 -> next = after ;

        return list1;
        
    }
};