class Solution {
    int solve(vector<int>& nums, int n, vector<int> &dp){
        
        // base cases
        if(n < 0) return 0;
        if(n == 0) return nums[0];

        // memo check
        if(dp[n] != -1) return dp[n];

        // include/exclude
        int include = solve(nums, n-2, dp) + nums[n];
        int exclude = solve(nums, n-1, dp);

        return dp[n] = max(include, exclude);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n-1, dp);
    }
};
