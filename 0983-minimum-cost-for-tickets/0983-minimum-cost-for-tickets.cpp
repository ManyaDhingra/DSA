class Solution {
    int solve(vector<int>& days, vector<int>& costs, int index, vector<int> &dp) {
        int n = days.size();
        if (index >= n) {
            return 0;
        }
        
        // use index for memo, not n
        if (dp[index] != -1) {
            return dp[index];
        }

        // 1-day pass
        int ans1 = costs[0] + solve(days, costs, index + 1, dp);

        // 7-day pass
        int i = index;
        while (i < n && days[i] < days[index] + 7) {
            i++;
        }
        int ans2 = costs[1] + solve(days, costs, i, dp);

        // 30-day pass
        i = index;
        while (i < n && days[i] < days[index] + 30) {
            i++;
        }
        int ans3 = costs[2] + solve(days, costs, i, dp);

        dp[index] = min(ans1, min(ans2, ans3));  // store at dp[index]
        return dp[index];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);   // dp by index
        return solve(days, costs, 0, dp);
    }
};
