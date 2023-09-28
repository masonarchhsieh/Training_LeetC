// https://leetcode.com/problems/diameter-of-binary-tree

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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        return max(help(root->left) + help(root->right), 
                max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    
    int help(TreeNode* root) {
        if (!root)
            return 0;
            
        return 1 + max(help(root->left), help(root->right));
    }
};