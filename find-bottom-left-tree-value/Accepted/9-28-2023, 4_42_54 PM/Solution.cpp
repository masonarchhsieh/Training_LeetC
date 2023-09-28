// https://leetcode.com/problems/find-bottom-left-tree-value

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
    int findBottomLeftValue(TreeNode* root) {
        if (!root)
            return -1;
        pair<int, int> res = { 0 , root->val };
        helper(root, res, 0);
        return res.second;
    }

    void helper(TreeNode* root, pair<int, int>& p, int level) {
        if (!root)
            return;
        if (root->left || root->right) {
            helper(root->left, p, level + 1);
            helper(root->right, p, level + 1);
        }
        if (p.first < level) {
            p = make_pair(level, root->val);
        }
    }
};