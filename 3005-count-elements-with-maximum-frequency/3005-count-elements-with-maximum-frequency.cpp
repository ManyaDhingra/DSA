class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int maxi = INT_MIN;
        int ans = 0;
        for(auto i : m){
            if(i.second > maxi){
                maxi = i.second;
                ans = i.second;
            }
            else if(i.second == maxi){
                ans += i.second;
            }
        }
        return ans;
    }
};