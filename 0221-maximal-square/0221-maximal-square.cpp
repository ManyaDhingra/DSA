class Solution {
    int solve(vector<vector<char>>& matrix, int m, int n, int i, int j, int &maxi){
        if(i>=m || j >= n){
            return 0;
        }
        int right = solve(matrix, m, n, i+1, j, maxi);
        int down =  solve(matrix, m, n, i, j+1, maxi);
        int dia = solve(matrix, m, n, i+1, j+1, maxi);

        if(matrix [i][j] == '1'){
            int ans = min(right, min(down, dia))+1;
            maxi = max(maxi, ans);
            return ans;

        }
        else{
            return 0 ;
        }
        
    
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 0;
        solve(matrix, m,n, 0, 0 , maxi);
        return maxi*maxi;
    }
};