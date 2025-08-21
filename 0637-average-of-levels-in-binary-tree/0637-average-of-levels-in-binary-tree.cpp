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
    int lvlLen(TreeNode* root) {
        if (root == NULL) return 0;
        int leftLvl = lvlLen(root->left);
        int rightLvl = lvlLen(root->right);
        return max(leftLvl, rightLvl) + 1;
    }

    void getLevelSum(TreeNode* root, int level, int currLevel, long long &sum, int &count) {
        if (!root) return;

        if (currLevel == level) {
            sum += root->val;
            count++;
        } else {
            getLevelSum(root->left, level, currLevel + 1, sum, count);
            getLevelSum(root->right, level, currLevel + 1, sum, count);
        }
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        int levels = lvlLen(root);  
        for (int lvl = 0; lvl < levels; lvl++) {
            long long sum = 0;
            int count = 0;
            getLevelSum(root, lvl, 0, sum, count);
            ans.push_back((double)sum / count);
        }

        return ans;
    }
};
