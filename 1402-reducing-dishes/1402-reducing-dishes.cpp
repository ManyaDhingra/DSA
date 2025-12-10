class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int i = n-1; i>=0 ; i--){ //index
            for(int j = n-1; j>= 0; j--){ //time
                int include = satisfaction[i]*(j+1) + next[j+1];
                int exclude = 0 + curr[j];

                curr[j] = max(include, exclude);
            }
            next = curr;
        }

        return next[0];
        
     
    }
};