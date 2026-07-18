class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        string ans = "";

        for(char ch : s){
            if(ch == y)
                ans += ch;
        }

        for(char ch : s){
            if(ch != x && ch != y)
                ans += ch;
        }

        for(char ch : s){
            if(ch == x)
                ans += ch;
        }

        return ans;
    }
};