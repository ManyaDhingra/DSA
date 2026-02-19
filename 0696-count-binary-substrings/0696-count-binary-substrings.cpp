class Solution {
public:
    int countBinarySubstrings(string s) {

        int pre = 0;
        int curr = 1;
        int ans = 0;

        for(int i = 1 ; i<s.length() ; i++){
            if(s[i] == s[i-1]){

                curr++;

            }
            else{
                ans += min(pre, curr);
                pre = curr;
                curr = 1;
            }
        }

        ans += min(pre, curr);
        return ans;
        
    }
};