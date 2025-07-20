class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            while (!ans.empty() && ans.back() > 0 && curr < 0) {
                if (abs(ans.back()) < abs(curr)) {
                    ans.pop_back();
                    continue;
                } else if (abs(ans.back()) == abs(curr)) {
                    ans.pop_back();
                    curr = 0;
                    break;
                } else {
                    curr = 0;
                    break;
                }
            }
            if (curr != 0) {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
