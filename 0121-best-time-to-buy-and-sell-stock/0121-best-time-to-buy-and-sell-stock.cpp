class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProf = 0;

        for(int i = 0 ; i < prices.size() ; i++){
            minPrice = min(minPrice, prices[i]);
            maxProf = max(maxProf, abs(minPrice - prices[i]));
        }

        return maxProf;

        
    }
};