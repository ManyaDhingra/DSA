class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int pos = 1;
        int first = -1;
        int last = -1;
        
        int minDist = INT_MAX;
        int maxDist = -1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != NULL && curr->next != NULL) {
            
            ListNode* next = curr->next;

            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (first == -1) {

                    first = pos;
                } 
                else {
                  
                    minDist = min(minDist, pos - last);

                    maxDist = pos - first;
                }

                last = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        if (first == -1 || first == last) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};