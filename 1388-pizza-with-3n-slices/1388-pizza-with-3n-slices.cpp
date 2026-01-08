class Solution {
   /* int sol(int index, int endIndex, vector<int>& slices, int n){
        if(n==0|| index > endIndex){
            return 0;
        }

        int include = slices[index] + sol(index + 2, endIndex, slices, n-1);
        int exclude = 0 + sol(index+1,endIndex, slices, n);

        return max(include, exclude);
    }*/
    int solMem(int index, int endIndex, vector<int>& slices, int n, vector <vector<int>> &dp){
        
        if(n==0|| index > endIndex){
            return 0;
        }
        if(dp[index][n] != -1){
            return dp[index][n];
        }

        int include = slices[index] + solMem(index + 2, endIndex, slices, n-1, dp);
        int exclude = 0 + solMem(index+1,endIndex, slices, n, dp);
        dp[index][n] = max(include, exclude);

        return dp[index][n];
    }
  
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector <vector<int>>dp1(k, vector<int> (k, -1));
        int case1 = solMem(0,k-2, slices, k/3, dp1);
        vector <vector<int>>dp2(k, vector<int> (k, -1));
        int case2 = solMem(1, k-1, slices, k/3, dp2);
        return max(case1, case2);
    }
};