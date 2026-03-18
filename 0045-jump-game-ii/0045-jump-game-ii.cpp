class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int last = 0;
        int dis = 0;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            dis = max(dis, i+nums[i]);
            if(i==last){
                jumps++;
                last = dis;
            }
        }
        return jumps;

        
    }
};