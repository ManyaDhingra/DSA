class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        map<int,int> mp;

        for(int x : nums){
            mp[x]++;
        }

        vector<int> result;

        for(auto it : mp){
            while(it.second--){
                result.push_back(it.first);
            }
        }

        return result;
    }
};