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
    TreeNode* bst (vector<int>& preorder, int& i , int maxVal){
        if(i >= preorder.size() || preorder[i] > maxVal){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = bst(preorder, i, root->val);       
        root->right = bst(preorder, i, maxVal);          
        return root;

        
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i = 0;
        return bst(preorder, i , INT_MAX);
    }
};