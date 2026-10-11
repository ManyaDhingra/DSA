class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0;
        int size = nums.size();
        int ans = 0;

        deque<int> maxD;
        deque<int> minD;

        for(int i = 0 ; i < size ; i++){
            while(!maxD.empty() && nums[maxD.back()] <= nums[i]){
                maxD.pop_back();
            }
            maxD.push_back(i);

            while(!minD.empty() && nums[minD.back()] >= nums[i]){
                minD.pop_back();
            }
            minD.push_back(i);

            while(nums[maxD.front()] - nums[minD.front()] > limit){
                if(maxD.front() == l){
                    maxD.pop_front();
                }
                if(minD.front() == l){
                    minD.pop_front();
                }
                l++;
            }
            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};