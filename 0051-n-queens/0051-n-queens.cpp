class Solution {
public:

    void addSol(vector<vector<string>> &board,
                vector<vector<string>> &ans,
                int n){

        vector<string> temp;

        for(int i = 0 ; i < n ; i++){

            string row = "";

            for(int j = 0 ; j < n ; j++){
                row += board[i][j];
            }

            temp.push_back(row);
        }

        ans.push_back(temp);
    }


    bool isSafe(int row, int col,
                vector<vector<string>> &board,
                int n){

        int x, y;

        // check row left
        x = row;
        y = col;
        while(y >= 0){
            if(board[x][y] == "Q")
                return false;
            y--;
        }

        // upper diagonal
        x = row;
        y = col;
        while(x >= 0 && y >= 0){
            if(board[x][y] == "Q")
                return false;
            x--;
            y--;
        }

        // lower diagonal
        x = row;
        y = col;
        while(x < n && y >= 0){
            if(board[x][y] == "Q")
                return false;
            x++;
            y--;
        }

        return true;
    }


    void sol(int col,
             vector<vector<string>> &board,
             vector<vector<string>> &ans,
             int n){

        if(col == n){
            addSol(board, ans, n);
            return;
        }

        for(int row = 0 ; row < n ; row++){

            if(isSafe(row, col, board, n)){

                board[row][col] = "Q";

                sol(col+1, board, ans, n);

                board[row][col] = ".";
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> board(n, vector<string>(n, "."));

        vector<vector<string>> ans;

        sol(0, board, ans, n);

        return ans;
    }
};
