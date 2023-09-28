// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (height(root->left) == height(root->right))
            return root;

        if (height(root->left) > height(root->right))
            root = root->left;
        else
            root = root->right;
        
        return lcaDeepestLeaves(root);     
    }
    
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
    
};