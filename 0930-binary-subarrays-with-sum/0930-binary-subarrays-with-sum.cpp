class Solution {
public:
    int count(vector<int>& nums, int goal){
        if(goal < 0){
            return 0;
        }
        int left = 0;
        int ans = 0;
        int sum = 0;

        for (int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];

            while(sum > goal){
                sum = sum - nums[left];
                left++;
            }

            ans += i-left+1;
            
        }
        return ans;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return count(nums, goal) - count(nums, goal-1);
    }
};