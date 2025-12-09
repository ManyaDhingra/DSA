class Solution {
    int sol(vector<int>& obstacles, int currlane, int pos, vector<vector<int>>& dp){
        int n = obstacles.size()-1;
        if(pos == n){
            return 0;
        }
        if(dp[currlane][pos] != -1){
            return dp[currlane][pos];
        }

        int ans = INT_MAX;
        if(obstacles[pos + 1] != currlane){
            return sol(obstacles, currlane, pos+1, dp);
        }

        for(int i = 1 ; i <= 3; i++){
            if(currlane != i && obstacles[pos] != i){
                ans = min(ans, 1+sol(obstacles, i , pos, dp));
            }
        }
        dp[currlane][pos] = ans;
        return dp[currlane][pos];
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4, vector<int> (obstacles.size(), -1)); 
        return sol(obstacles, 2, 0, dp);
        
    }
};