class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size() && nums[i] <= target){
            if(nums[i] == target){
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};