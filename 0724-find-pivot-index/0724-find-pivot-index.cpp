class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int pre = 0;
        int suf = 0;
        vector<int> ans(n, 0);
        for(int i = 0 ; i < n ; i++){
            ans[i] = pre;
            pre += nums[i];
        }
        for(int i = n-1 ; i >= 0 ; i--){
            ans [i] -= suf;
            suf += nums[i];
        }

        for(int i = 0 ; i < n ; i++){
            if(ans[i] == 0){
                return i;
            }
        }
        return -1;
    }
};