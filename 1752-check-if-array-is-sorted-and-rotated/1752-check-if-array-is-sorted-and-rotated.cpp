class Solution {
public:

    bool isSorted(vector<int>& nums){
        for(int i = 0 ; i < nums.size()-1 ; i++){
                if(nums[i] > nums[i+1]){
                    return false;
                }
        }
        return true;
    }

    bool rotSort(vector<int>& nums){
        int n = nums.size();
        for(int x = 1 ; x < n ; x++){
            vector<int> B(n);
            for(int i = 0 ; i< nums.size(); i ++){
                B[i] = nums[(i+x) % n];
            }
            if(isSorted(B)){
                return true;
            }
        }
        return false;
    }
    bool check(vector<int>& nums) {

        if(isSorted(nums)){
            return true;
        }
        return rotSort(nums);
    }
};