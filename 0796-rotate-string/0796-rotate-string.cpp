class Solution {
public:
    string rotate(string s, int k){
        int n = s.size();
        k = k%n;
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+k);
        reverse(s.begin()+k, s.end());
        return s;
    }
    bool rotateString(string s, string goal) {
        for(int i = 0 ; i < s.size() ; i++){
            rotate(s,i);
            if(rotate(s,i) == goal){
                return true;
            }
        }
        return false;
    }
};