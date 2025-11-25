/*class Solution {
    int solve(vector<int>& nums, int target, vector<int> &dp){
        
        if(target<0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[target] != -1){
            return dp[target];
        }

        int ways = 0;
        for(int i = 0 ; i< nums.size(); i++){
            ways += solve(nums, target - nums[i], dp);

        }
        dp[target] = ways;
        return ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target+1, -1);

        return solve(nums,target,dp);
        
    }
};
*/

// tabulation 
class Solution {
    int solve(vector<int>& nums, int target){
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        
        for(int i = 1 ; i <= target ; i++){

            for(int j = 0; j< nums.size(); j++){
                if (i - nums[j] >= 0){
                    dp[i] += dp[i - nums[j]];
                }
                
            }
           

        }
    
        return (int)dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {

        return solve(nums,target);
        
    }
};
