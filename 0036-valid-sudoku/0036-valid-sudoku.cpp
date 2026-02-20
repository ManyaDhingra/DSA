class Solution {
public:

    bool isSafe(vector<vector<char>>& board,
                int row, int col, char num){

        for(int i=0;i<9;i++){
            if(i != col && board[row][i] == num)
                return false;
        }

        for(int i=0;i<9;i++){
            if(i != row && board[i][col] == num)
                return false;
        }

        int startRow = (row/3)*3;
        int startCol = (col/3)*3;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int r = startRow+i;
                int c = startCol+j;

                if((r != row || c != col) &&
                    board[r][c] == num)
                    return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j] != '.'){

                    char num = board[i][j];

                    if(!isSafe(board,i,j,num))
                        return false;
                }
            }
        }

        return true;
    }
};
