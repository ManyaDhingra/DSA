class Solution {
public:
    bool isSafe(int x, int y, vector<vector<char>>& board,vector<vector<int>> &walked, string& word, int m, int n){

        if(x>=0 && x<m && y>=0 && y<n && walked[x][y] == 0){
            return true;
        }
        return 0;
    }

    bool sol(vector<vector<char>>& board,int x, int y, int m,int n, string& word, vector<vector<int>> &walked, string &path){

        int w= word.length();
        if(path == word){
            return true;
        }

        if(path.length() >= word.length())
            return false;

        walked[x][y] = 1;

        if(isSafe(x-1,y,board,walked,word,m,n)){
            path.push_back(board[x-1][y]);
            if(sol(board,x-1,y,m,n,word,walked,path))
                return true;
            path.pop_back();
        }

        if(isSafe(x,y-1,board,walked,word,m,n)){
            path.push_back(board[x][y-1]);
            if(sol(board,x,y-1,m,n,word,walked,path))
                return true;
            path.pop_back();
        }

        if(isSafe(x+1,y,board,walked,word,m,n)){
            path.push_back(board[x+1][y]);
            if(sol(board,x+1,y,m,n,word,walked,path))
                return true;
            path.pop_back();
        }

        if(isSafe(x,y+1,board,walked,word,m,n)){
            path.push_back(board[x][y+1]);
            if(sol(board,x,y+1,m,n,word,walked,path))
                return true;
            path.pop_back();
        }

        walked[x][y] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> walked(m, vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(board[i][j] == word[0]){

                    string path = "";
                    path.push_back(board[i][j]);

                    if(sol(board,i,j,m,n,word,walked,path))
                        return true;
                }
            }
        }

        return false;
    }
};

