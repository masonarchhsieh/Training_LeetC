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
    int res = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root)
            return 0;
        res = max(res, helper(root, root));
        longestUnivaluePath(root->left);
        longestUnivaluePath(root->right);
        return res;
    }

    int helper(TreeNode* root, TreeNode* itr) {
        if (!root)
            return 0;
        if (!itr)
            return 0;
        if (root->val != itr->val)
            return 0;
        if (root == itr)
            return helper(root, itr->left) + helper(root, itr->right);
        return 1 + max(helper(root, itr->left), helper(root, itr->right));
    }
};