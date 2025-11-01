class Solution {
    int solve(int n, int i, vector<int> &arr){
        
        if(i==n){
            return 1;
        }

        if(i>n){
            return 0;
        }

        if (arr[i] != -1)
            return arr[i];

        arr[i] = solve(n, i+1, arr) + solve(n, i+2, arr);
        return arr[i];
    }
public:
    int climbStairs(int n) {
        vector<int> arr(100, -1);
        return solve(n,0, arr);

    }
};