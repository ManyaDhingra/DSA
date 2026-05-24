class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map <int , int> mp;

        for(int i : nums){
            mp[i]++;
        }

        for(int i : nums){
            if(mp[i] == 1){
                return i;
            }
        }

        return 0;
        
    }
};