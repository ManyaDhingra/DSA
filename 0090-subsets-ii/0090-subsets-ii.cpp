class Solution {
public:

    void sol(vector<int>& nums, int i, vector<vector<int>> &ans, vector<int>& curr){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        sol(nums, i+1, ans, curr);
        curr.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }

        sol(nums, i+1, ans , curr);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        vector<vector<int>> ans;
        vector<int> curr;
        sol(nums, 0 , ans, curr);
        return ans;
        
    }
};