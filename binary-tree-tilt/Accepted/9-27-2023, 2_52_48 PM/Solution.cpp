// https://leetcode.com/problems/binary-tree-tilt

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
    int getSum(TreeNode* root) {
        if (!root)
            return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }

    int findTilt(TreeNode* root) {
        if (!root)
            return 0;
        int left_s = getSum(root->left);
        int right_s = getSum(root->right);

        return abs(right_s - left_s) + findTilt(root->left) + findTilt(root->right);
    }
};