class Solution {
public:

    long long count(vector<int>& nums, int k){
        int left = 0;
        long long ans = 0;   
        int odd = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] % 2 == 1){
                odd++;
            }

            while(odd > k){
                if(nums[left] % 2 == 1){
                    odd--;
                }
                left++;
            }
            
            ans += (i - left + 1);
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums, k) - count(nums, k-1);
    }
};