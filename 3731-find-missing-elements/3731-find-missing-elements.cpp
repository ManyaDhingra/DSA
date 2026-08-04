class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums[0];
        int m = nums[nums.size()-1];
        int j = 0;
        for(int i = n ; i <= m ; i++){
            
                if(i == nums[j] && j < nums.size()){
                    j++;
                }
                else{
                    ans.push_back(i);

                }
            
           
        }
        return ans;
        
    }
};