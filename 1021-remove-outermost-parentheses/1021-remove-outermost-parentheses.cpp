class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "" ;
        int paren = 0 ;

        for(char c : s){
            if(c == '('){
                if(paren > 0){
                    ans += c;
                }
                paren++;
            }
            else{
                paren--;
                if(paren > 0){
                    ans += c ;
                }
            }
        }
        return ans;
        
    }
};