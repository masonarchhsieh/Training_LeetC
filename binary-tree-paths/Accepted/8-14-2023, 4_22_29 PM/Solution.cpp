// https://leetcode.com/problems/binary-tree-paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root, res, "");

        return res;
    }

    void helper(TreeNode *root, vector<string>& list, string prev) {
        string tmp = prev + std::to_string(root->val);
        if (!root->left && !root->right)
            list.push_back(tmp);
        if (root->left)
            helper(root->left, list, tmp + "->");
        if (root->right)
            helper(root->right, list, tmp + "->");
    }
};