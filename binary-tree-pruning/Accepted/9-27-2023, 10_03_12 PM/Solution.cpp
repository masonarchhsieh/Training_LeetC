// https://leetcode.com/problems/binary-tree-pruning

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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root)
            return root;
        if (!hasOne(root)) {
            return NULL;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }

    bool hasOne(TreeNode* root) {
        if (!root)
            return false;
        if (root->val == 1)
            return true;
        
        return hasOne(root->left) | hasOne(root->right);
    }


};