class Solution {
    int sol(vector<int>& values, int i, int j, vector<vector<int>>& dp){
        
        if(i+1 == j){
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans,
          values[i] * values[j] * values[k]
          + sol(values, i, k, dp)
          + sol(values, k, j, dp));
        

        }
        dp[i][j] = ans;
        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return sol(values, 0, values.size()-1, dp);
    }
};