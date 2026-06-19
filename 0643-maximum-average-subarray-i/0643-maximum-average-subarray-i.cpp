class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double ans = 0;
        double maxi = INT_MIN;

        for(int i = 0 ; i < k ; i++){
            ans +=  nums[i];
        }
        maxi = max(maxi, ans/(k * 1.0));

        for(int i = k ; i < nums.size() ; i ++){
            ans += nums[i];
            ans -= nums[i-k];
            maxi = max(maxi, ans/(k * 1.0));
        }

        return maxi;
        
    }
};