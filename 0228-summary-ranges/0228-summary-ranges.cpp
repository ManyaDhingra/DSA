class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> ans;

        for(int i = 0 ; i < nums.size() ; i++){
            int curr = nums[i];
            while(i+1 < nums.size() && nums[i+1] == nums[i]+1){
                i++;
            }

            if(curr == nums[i]){
                ans.push_back(to_string(curr));
            }
            else{
                ans.push_back(to_string(curr) + "->" + to_string(nums[i]));
            }
        }

        return ans;
        
    }
};