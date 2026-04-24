class Solution {
public:

    int sumDiv(vector<int>& nums, int n, int mid){
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i]/mid;

            if(nums[i] % mid != 0){
                sum += 1;
            }
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while(low <= high){
            int mid = (low + high) / 2;

            if(sumDiv(nums, n , mid) <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};