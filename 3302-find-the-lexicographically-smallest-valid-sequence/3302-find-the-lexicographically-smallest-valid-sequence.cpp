class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

     
        vector<int> dp(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                dp[i] = dp[i + 1] + 1;
                j--;
            } else {
                dp[i] = dp[i + 1];
            }
        }

        vector<int> ans(m);

        int i = 0;
        j = 0;

        while (i < n && j < m) {

            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }
            else {
              
                if (dp[i + 1] >= m - 1 - j) {
                    ans[j] = i;
                    j++;
                    i++;
                    break;
                }
            }

            i++;
        }

        if (j < m && i == n)
            return {};

        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }
            i++;
        }

        if (j != m)
            return {};

        return ans;
    }
};