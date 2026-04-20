class Solution {
public:
    void sol(int open, int close, string s, int n, vector<string> &ans){
        if(s.length() == 2*n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            sol(open + 1, close, s + '(' , n, ans);
        }

        if(close < open){
            sol(open, close + 1, s + ')' , n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        sol(0, 0 , "", n, ans);
        return ans;
        
    }
};