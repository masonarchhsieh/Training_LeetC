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
        int max_min_diff = max(root->val - findMin(root->left), root->val - findMin(root->right));
        int min_max_diff = max(findMax(root->left) - root->val, findMax(root->right) - root->val);
        
        return max(max(max(maxAncestorDiff(root->left), maxAncestorDiff(root->right)), max_min_diff), min_max_diff);
    }
    
    
    int findMin(TreeNode *root) {
        if (!root)
            return INT_MAX;
        return min(min(findMin(root->left), findMin(root->right)), root->val);
    }
    
    int findMax(TreeNode *root) {
        if (!root)
            return 0;
        return max(max(findMax(root->left), findMax(root->right)), root->val);
    }
};