class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        if(nums.size() == 0){
            return 0;
        }

        int count = 0;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i] < nums[i+1] && (nums[i+1] - nums[i]) == 1){
                count++;
            }
        }

        return count+1;
        
    }
};