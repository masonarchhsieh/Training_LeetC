// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

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
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return INT_MIN;
        
        
        int maxanc_min = max(root->val - findMinChild(root->left), root->val - findMinChild(root->right));
        int maxanc_max = max(findMaxChild(root->left) - root->val, findMaxChild(root->right) - root->val);

        return max(max(max(maxAncestorDiff(root->left), maxAncestorDiff(root->right)), maxanc_min), maxanc_max);
    }
    
    int findMinChild(TreeNode* root) {
        if (!root)
            return INT_MAX;
        
        return min(min(findMinChild(root->left), findMinChild(root->right)), root->val);
    }
    
    int findMaxChild(TreeNode* root) {
        if (!root)
            return 0;
        
        return max(max(findMaxChild(root->left), findMaxChild(root->right)), root->val);
    }
};