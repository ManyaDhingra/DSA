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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        if(root -> left == NULL && root -> right == NULL){
            return targetSum == root -> val;
        }

        int remains = targetSum - root -> val;

        return hasPathSum(root -> right, remains) || hasPathSum(root -> left, remains);
    }
};