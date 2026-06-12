class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans; 
        map<int, int> freq;
        for(int i : arr1){
            freq[i]++;
        }

        for(int i : arr2){
            while(freq[i] > 0){
                ans.push_back(i);
                freq[i]--;
            }
        }

        for(auto it : freq){
            while(it.second > 0){
                ans.push_back(it.first);
                it.second--;
            }
        }
        return ans;
        
    }
};