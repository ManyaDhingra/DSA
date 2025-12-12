class Solution {
    int solve(vector<int>& nums, int n, int curr, int prev, vector<vector<int>> &dp){
        if(curr== n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        int inc = 0;
        if(prev==-1 || nums[curr]> nums[prev]){
            inc = 1+ solve (nums, n, curr+1, curr, dp);
        }

        int exclude = 0 + solve(nums, n, curr+1, prev, dp);
        dp[curr][prev+1]= max(inc, exclude);

        return dp[curr][prev+1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return solve(nums, n, 0,-1, dp);
    }
};