class Solution {
    bool check(vector<vector<int>>& mat, int row, int col){

        int m = mat.size();
        int n = mat[0].size();

        // check row
        for(int j = 0; j < n; j++){
            if(j != col && mat[row][j] == 1)
                return false;
        }

        // check column
        for(int i = 0; i < m; i++){
            if(i != row && mat[i][col] == 1)
                return false;
        }

        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 1 && check(mat, i, j) == true){
                    count++;                    
                }
            }
        }
        return count;
    }
};