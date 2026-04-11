class Solution {
public:
    bool isPalin(string s){
    string rev = s;
    reverse(rev.begin(), rev.end());
    return rev == s;
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                string sub = s.substr(i, j - i + 1);

                if(isPalin(sub) && sub.size() > ans.size()){
                    ans = sub;
                }
            }
        }
        return ans;
        
    }
};