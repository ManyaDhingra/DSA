class Solution {
public:

    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<pair<int,int>> dir = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };

        // first pass
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                int live = 0;

                // count neighbors
                for(auto d : dir){

                    int ni = i + d.first;
                    int nj = j + d.second;

                    if(ni >= 0 && nj >= 0 &&
                       ni < m && nj < n &&
                       abs(board[ni][nj]) == 1){

                        live++;
                    }
                }

                // live cell dies
                if(board[i][j] == 1 &&
                   (live < 2 || live > 3)){

                    board[i][j] = -1;
                }

                // dead cell becomes live
                if(board[i][j] == 0 && live == 3){

                    board[i][j] = 2;
                }
            }
        }

        // second pass
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                if(board[i][j] > 0){
                    board[i][j] = 1;
                }

                else{
                    board[i][j] = 0;
                }
            }
        }
    }
};