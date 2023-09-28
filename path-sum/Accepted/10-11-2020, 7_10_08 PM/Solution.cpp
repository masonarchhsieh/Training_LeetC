// https://leetcode.com/problems/path-sum

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        
        if (root->right == nullptr && root->left == nullptr && root->val == sum)
            return true;
        if (root->right == nullptr)
            return help(root->left, sum - root->val);
        if (root->left == nullptr)
            return help(root->right, sum - root->val);
        
        return help(root, sum);
    }
    
    bool help(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        
        if (root->val == sum && (root->left == nullptr && root->right == nullptr))
            return true;
        
        return help(root->left, sum - root->val) || help(root->right, sum - root->val);
    }
};