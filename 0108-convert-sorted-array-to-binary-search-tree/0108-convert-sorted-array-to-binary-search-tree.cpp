/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* sol(vector<int>& nums , int left , int right){

        if(left > right){
            return NULL;
        }

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode (nums[mid]);

        root->left = sol(nums, left, mid - 1);
        root->right = sol(nums, mid + 1, right);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return sol(nums, 0, nums.size()-1);
        
    }
};