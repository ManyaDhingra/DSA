#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    vector<vector<int>> solve(vector<int>& candidates, int target, int start) {
        
        if (target == 0) {
            return { { } };               // one valid combination: empty suffix
        }
        if (target < 0) {
            return vector<vector<int>>(); // no solution
        }

        vector<vector<int>> ans;
        int n = candidates.size();
        for (int i = start; i < n; ++i) {
            if (candidates[i] > target) continue; 

            auto subs = solve(candidates, target - candidates[i], i);
            for (auto &comb : subs) {
                // prepend current candidate to each returned combination
                vector<int> newComb;
                newComb.push_back(candidates[i]);
                newComb.insert(newComb.end(), comb.begin(), comb.end());
                ans.push_back(move(newComb));
            }
        }
        return ans;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        return solve(candidates, target, 0);
    }
};
