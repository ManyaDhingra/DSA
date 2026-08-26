class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        
        for (int i = 0; i < s.size(); i++) {
            int cnt = 0;
            
            for (int j = i; j < s.size(); j++) {
                if (s[j] == '1') cnt++;
                
                if (cnt == k) {
                    string cur = s.substr(i, j - i + 1);
                    
                    if (ans == "" || cur.size() < ans.size() ||
                        (cur.size() == ans.size() && cur < ans)) {
                        ans = cur;
                    }
                    break;
                }
            }
        }
        
        return ans;
    }
};