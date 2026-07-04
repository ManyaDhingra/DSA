class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0  ; i < n ; i ++){
            for(int j = i+1 ; j < n ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int startrow = 0;
        int endrow = n-1 ;
        int startcol = 0 ;
        int endcol = n-1;

        for(int i = 0 ; i < n ; i++){
            int start = 0;
            int end = n-1;

            while(start <= end){
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }



        
    }
};