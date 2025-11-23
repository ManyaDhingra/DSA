class Solution {
    bool solve(vector<vector<int>>& dp, vector<int> &nums, int index, int target) {
        if (target == 0) return true;        
        if (index < 0 || target < 0) return false;

        if (dp[index][target] != -1) {
            return dp[index][target];          
        }

        bool include = solve(dp, nums, index - 1, target - nums[index]);
        bool exclude = solve(dp, nums, index - 1, target);

        dp[index][target] = (include || exclude); 
        return dp[index][target];                 
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();                       
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));  

        return solve(dp, nums, n - 1, target);
    }
};
