// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        return helper(root, val);
    }

    TreeNode* helper(TreeNode* root, int val) {
        if (!root)
            return nullptr;
        if (root->left && root->val > val)
            root->left = helper(root->left, val);
        else if (root->right && root->val < val)
            root->right = helper(root->right, val);
        else if (!root->left && root->val > val)
            root->left = new TreeNode(val);
        else if (!root->right && root->val < val)
            root->right = new TreeNode(val);
        return root;
    }
};