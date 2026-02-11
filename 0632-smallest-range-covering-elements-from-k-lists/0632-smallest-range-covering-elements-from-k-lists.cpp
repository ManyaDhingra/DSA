class node{
    public: 
    int data, row, col;
    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a-> data > b-> data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        int k = nums.size();

        priority_queue<node* , vector<node*>, compare> pq;

        for(int i = 0 ; i<k; i++){
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            pq.push(new node(element, i, 0));
        }
        int start = mini, end = maxi;
        while(!pq.empty()){
            node* temp = pq.top();
            pq.pop();
            mini = temp -> data;
            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }

            if(temp->col + 1 < nums[temp->row].size()){
                maxi = max(maxi, nums[temp-> row][temp-> col+1]);
                pq.push(new node(nums[temp-> row][temp-> col+1], temp-> row, temp-> col+1));
            }
            else{
                break;
            }
        }
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};