class Solution {
public:
    string reverseWords(string s) {
        int l = s.size();
        vector<pair<int, int>> wordPositions; 
        int i = 0;
        while (i < l) {
            while (i < l && s[i] == ' ') i++;
            if (i == l) break;
            
            int start = i; 
            while (i < l&& s[i] != ' ') i++;
            int end = i - 1; 
            wordPositions.push_back({start, end});
        }
        
        string result = "";
        for (int j = wordPositions.size() - 1; j >= 0; --j) {
            string word = s.substr(wordPositions[j].first, wordPositions[j].second - wordPositions[j].first + 1);
            result += word;
          
            if (j != 0) result += " ";
        }
        
        return result;
    }
};