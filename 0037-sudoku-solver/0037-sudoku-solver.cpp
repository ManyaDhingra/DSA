class Solution {
public:

    bool isSafe(vector<vector<char>>& board,
                int row, int col, char num){

    
        for(int i=0;i<9;i++){
            if(board[row][i] == num)
                return false;
        }


        for(int i=0;i<9;i++){
            if(board[i][col] == num)
                return false;
        }

        
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[startRow+i][startCol+j] == num)
                    return false;
            }
        }

        return true;
    }

    bool sol(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j] == '.'){

                    for(char k='1'; k<='9'; k++){

                        if(isSafe(board,i,j,k)){

                            board[i][j] = k;

                            if(sol(board))
                                return true;

                            board[i][j] = '.';
                        }
                    }

                    return false; 
                }
            }
        }

        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        sol(board);
    }
};
