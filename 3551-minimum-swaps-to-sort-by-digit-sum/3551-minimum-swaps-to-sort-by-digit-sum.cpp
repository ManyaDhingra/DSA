
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            a[i] = {sum, nums[i]};
        }

        vector<int> order(n);
        for (int i = 0; i < n; i++)
            order[i] = i;

        sort(order.begin(), order.end(), [&](int i, int j) {
            if (a[i].first != a[j].first)
                return a[i].first < a[j].first;
            return a[i].second < a[j].second;
        });

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || order[i] == i)
                continue;

            int j = i, len = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = order[j];
                len++;
            }

            ans += len - 1;
        }

        return ans;
    }
};
