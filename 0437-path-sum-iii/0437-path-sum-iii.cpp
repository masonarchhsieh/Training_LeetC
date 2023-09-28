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
    void helper(TreeNode* root, long long targetSum) {
        if (!root)
            return;
        if (root->val == targetSum)
            res++;
        helper(root->left, targetSum - root->val);
        helper(root->right, targetSum - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        helper(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return res;
    }
};