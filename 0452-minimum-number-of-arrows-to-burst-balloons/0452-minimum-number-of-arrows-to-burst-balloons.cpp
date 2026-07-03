class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()){
            return 0;
        }

        sort(points.begin(), points.end(),[](vector<int>& a , vector<int>&b){
            return a[1] < b[1];
        });

        int cnt = 1;
        int end = points[0][1];

        for(int i = 0 ; i < points.size() ; i++){
            if(points[i][0] > end){
                cnt++;
                end = points[i][1];
            }
        }
        return cnt;
    }
};