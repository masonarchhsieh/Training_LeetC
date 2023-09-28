// https://leetcode.com/problems/sum-of-left-leaves

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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, 'M', sum);
        
        return sum;
    }
    
    void helper(TreeNode* node, char side, int& sum) {
        if (node == NULL)
            return;
        if (node->left == NULL && node->right == NULL) {
            if (side == 'L') {
                sum += node->val;
            }
        }
        else {
            helper(node->left, 'L', sum);
            helper(node->right, 'R', sum);
        }
        
    }
};