class Solution {
    int sol(vector<int>& values, int i, int j){
        if(i+1 == j){
            return 0;
        }
        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans,
          values[i] * values[j] * values[k]
          + sol(values, i, k)
          + sol(values, k, j));

        }
        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        return sol(values, 0, values.size()-1);
    }
};