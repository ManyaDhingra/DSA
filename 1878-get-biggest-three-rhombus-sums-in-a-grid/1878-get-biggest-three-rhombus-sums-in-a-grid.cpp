class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> s;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                s.insert(grid[i][j]);  // size 0 rhombus

                for(int k=1;i+2*k<m && j-k>=0 && j+k<n;k++){
                    int sum=0;

                    for(int t=0;t<k;t++) sum+=grid[i+t][j+t];
                    for(int t=0;t<k;t++) sum+=grid[i+k+t][j+k-t];
                    for(int t=0;t<k;t++) sum+=grid[i+2*k-t][j-t];
                    for(int t=0;t<k;t++) sum+=grid[i+k-t][j-k+t];

                    s.insert(sum);
                }
            }
        }

        vector<int> res;
        for(auto it=s.rbegin();it!=s.rend() && res.size()<3;it++)
            res.push_back(*it);

        return res;
    }
};