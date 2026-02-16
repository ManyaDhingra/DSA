class Solution {
public:

    bool isSafe(int x, int y,
            vector<vector<int>>& grid,
            vector<vector<int>>& walked,
            int m, int n){

    return x>=0 && x<m &&
           y>=0 && y<n &&
           grid[x][y] != -1 &&
           walked[x][y] == 0;
}


    void sol(int x, int y,
             vector<vector<int>>& grid,
             vector<vector<int>>& walked,
             int m, int n,
             int &ans,
             int remaining){

        if(grid[x][y] == 2){
            if(remaining == 0) 
                ans++;
            return;
        }

        walked[x][y] = 1;

        if(isSafe(x+1,y,grid,walked,m,n))
            sol(x+1,y,grid,walked,m,n,ans,remaining-1);

        if(isSafe(x-1,y,grid,walked,m,n))
            sol(x-1,y,grid,walked,m,n,ans,remaining-1);

        if(isSafe(x,y+1,grid,walked,m,n))
            sol(x,y+1,grid,walked,m,n,ans,remaining-1);

        if(isSafe(x,y-1,grid,walked,m,n))
            sol(x,y-1,grid,walked,m,n,ans,remaining-1);

        walked[x][y] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int startX, startY;
        int empty = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0)
                    empty++;

                if(grid[i][j] == 1){
                    startX = i;
                    startY = j;
                }
            }
        }

        vector<vector<int>> walked(m, vector<int>(n,0));

        int ans = 0;

        sol(startX,startY,grid,walked,m,n,ans,empty);

        return ans;
    }
};
