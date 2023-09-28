// https://leetcode.com/problems/convert-bst-to-greater-tree

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
    vector<int> v;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return root;
        int sum = 0;
        helper(root, sum);

        return root;
    }

    void helper(TreeNode* root, int &sum) {
        if (!root)
            return;
        helper(root->right, sum);
        sum += root->val;
        root->val = sum;
        helper(root->left, sum);
    }
};