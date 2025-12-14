class Solution {
    bool check(vector<int> base, vector<int> newBox){
        if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]){
            return true;
        }
        else{
            return false;
        }
    }
    int solve(int n, vector<vector<int>>& cuboids){
        vector<int> currRow(n+1, 0);
        vector<int> nexRow(n+1, 0);

        for(int curr = n-1 ; curr >= 0 ; curr --){
            for(int pre = curr-1 ; pre>=-1 ; pre--){
                int  take = 0;
                if(pre == -1 || check(cuboids[curr], cuboids[pre])){
                    take = cuboids[curr][2] + nexRow[curr+ 1];
                }
                int noTake = 0 + nexRow[pre+1];
                currRow[pre+1] = max(take, noTake);
            }
            nexRow = currRow;
        }
        return nexRow [0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        for(auto &a:cuboids){
            sort(a.begin(), a.end());
        }

        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids.size(), cuboids);
        
    }
};