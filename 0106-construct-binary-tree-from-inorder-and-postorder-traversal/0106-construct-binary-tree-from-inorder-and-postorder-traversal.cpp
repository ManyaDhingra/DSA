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
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap, int& postIndex) {
        if (inStart > inEnd) {
            return NULL;
        }

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];
        root->right = build(postorder, inorder, inIndex + 1, inEnd, inorderMap, postIndex);
        root->left = build(postorder, inorder, inStart, inIndex - 1, inorderMap, postIndex);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;
        return build(postorder, inorder, 0, inorder.size() - 1, inorderMap, postIndex);
    }
};
