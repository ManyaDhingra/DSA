class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int m = nums1.size();
        int n = nums2.size();

        for(int c : nums1){
            arr.push_back(c);
        }
        for(int c : nums2){
            arr.push_back(c);
        }
        double ans= 0;
        sort(arr.begin(), arr.end());
        int mid = (m+n)/2;
        int median = 0;
        if((m+n) % 2 == 0){
            median = arr[mid] + arr[mid-1];
            ans = median / 2.0;
        }
        else{
            median = arr[mid];
            ans = median;
        }
        return ans;


    }
};