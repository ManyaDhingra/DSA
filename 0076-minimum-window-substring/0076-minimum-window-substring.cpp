class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        if(s.size() < t.size()){
            return "";
        }
        unordered_map<char , int> map;
        for(char c : t){
            map[c]++;
        }
        int count = t.size();
        int l = 0;

        int start = 0;
        int len = INT_MAX;

        for(int r = 0 ; r < s.size() ; r++){
            if(map[s[r]] > 0){
                    count--;
            }
           map[s[r]]--;

           while(count == 0){
                if(r - l + 1 < len){
                    len = r - l + 1;
                    start = l;
                }
            map[s[l]]++;

            if(map[s[l]] > 0)
                count++;

            l++;
           }
        } 

        if(len == INT_MAX)
            return "";

        return s.substr(start, len);
        
    }
};