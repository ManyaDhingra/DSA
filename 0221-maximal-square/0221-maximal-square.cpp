class Solution {
/*  int solve(vector<vector<char>>& matrix, int m, int n, int i, int j, int &maxi, vector<vector<int>> &dp){
        if(i>=m || j >= n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = solve(matrix, m, n, i+1, j, maxi, dp);
        int down =  solve(matrix, m, n, i, j+1, maxi, dp);
        int dia = solve(matrix, m, n, i+1, j+1, maxi, dp);

        if(matrix [i][j] == '1'){
            dp[i][j] = min(right, min(down, dia))+1;
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];

        }
        else{
            dp[i][j] = 0;
            return 0 ;
        }
        
    
    }*/
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 0;
 /*     vector<vector<int>> dp(m, vector<int> (n, -1));
        solve(matrix, m,n, 0, 0 , maxi, dp);
        return maxi*maxi;
        */

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for( int i = m-1; i>=0 ; i--){
            for(int j = n-1; j >=0 ; j--){
                int right = dp[i][j+1];
                int down =  dp[i+1][j];
                int dia = dp[i+1][j+1];

                if(matrix [i][j] == '1'){
                    dp[i][j] = min(right, min(down, dia))+1;
                    maxi = max(maxi, dp[i][j]);

                }
                else{
                    dp[i][j] = 0;
                
                }
            }
        }
        return maxi * maxi;

    }
};