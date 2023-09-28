// https://leetcode.com/problems/root-equals-sum-of-children

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
    bool checkTree(TreeNode* root) {
        if (!root)
            return false;
        int left_val = (root->left)? root->left->val : 0;
        int right_val = (root->right)? root->right->val : 0;
        
        return root->val == left_val + right_val;
    }
};