class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>  mp;
        for(int c : nums){
            mp[c]++;
        }
        for(auto it : mp){
            if(it.second > 1){
                return true;
            }
        }

        return 0;
    }
};