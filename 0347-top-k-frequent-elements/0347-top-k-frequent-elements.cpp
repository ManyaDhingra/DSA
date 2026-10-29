class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int c : nums){
            mp[c]++;
        }

        vector<pair<int, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        int n = k;

        for (int i = 0; i < min(n, (int)v.size()); i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};