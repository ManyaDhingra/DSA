class Solution {
    int solve(int target, vector<int> &coins, vector<int> &dp){

        dp[0] = 0;

        for(int i = 1; i <= target; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }            
        }

        return dp[target];
           
    } 
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1, INT_MAX);

        int ans = solve(amount,coins, dp);
        if(ans == INT_MAX){
            return -1;
        }

        return ans;  
        
    }
};