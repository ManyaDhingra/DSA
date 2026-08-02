class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int newC){
        int n = image.size();
        int m = image[0].size();

        if(sr < 0 || sc < 0 || sr >= n || sc >= m){
            return ;
        }

        if(image[sr][sc] != newC){
            return ;
        }

        image[sr][sc] = color;
        dfs(image, sr+1, sc, color, newC);
        dfs(image, sr-1, sc, color, newC);
        dfs(image, sr, sc+1, color, newC);
        dfs(image, sr, sc-1, color, newC);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int newC = image[sr][sc];
        if(newC == color){
            return image;
        }

        dfs(image, sr, sc, color, newC);
        return image;
    }
};