class Solution {
public:

    int countBit(int num){
        int count = 0;
        while(num>0){
            if(num % 2 == 1){
                count++;
            }
            num = num/2;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> map;
        for(int i = 0; i < arr.size(); i++){
            int bits = countBit(arr[i]);
            map[bits].push_back(arr[i]);
        }

        vector<int> ans;

        for(auto &a: map){
            vector<int> &v = a.second;

            sort(v.begin(), v.end()); 

            for(int i = 0; i < v.size(); i++){
                ans.push_back(v[i]);
        }
        }
        return ans;
        
    }
};