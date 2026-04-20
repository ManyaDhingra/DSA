class Solution {
    vector<vector<int>> solve(vector<int>& candidates, int target, int start) {
        
        if (target == 0) {
            return { { } };               
        }
        if (target < 0) {
            return vector<vector<int>>(); 
        }

        vector<vector<int>> ans;
        int n = candidates.size();
        for (int i = start; i < n; ++i) {
            if (candidates[i] > target) continue; 

            auto subs = solve(candidates, target - candidates[i], i+1);
            for (auto &comb : subs) {
                // prepend current candidate to each returned combination
                vector<int> newComb;
                newComb.push_back(candidates[i]);
                newComb.insert(newComb.end(), comb.begin(), comb.end());
        
                ans.push_back(move(newComb));
            }
        }
        sort(ans.begin(), ans.end());          // sort first
ans.erase(unique(ans.begin(), ans.end()), ans.end());
return ans;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return solve(candidates, target, 0);
    }
};