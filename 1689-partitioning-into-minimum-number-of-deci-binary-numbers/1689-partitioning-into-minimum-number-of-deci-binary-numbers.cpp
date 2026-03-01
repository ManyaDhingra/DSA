class Solution {
public:
    int minPartitions(string n) {
        // logic : jo max digit hai number ka vhi answer hai bbg
        int maxi = 0;
        for(char c : n){
            maxi = max(maxi, c-'0');
        }
        return maxi;
        
    }
};