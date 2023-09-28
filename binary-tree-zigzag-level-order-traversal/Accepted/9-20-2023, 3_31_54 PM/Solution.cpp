// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(res, root, 0);
        for (auto i = 1; i < res.size(); i+=2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }

    void helper(vector<vector<int>> &res, TreeNode* root, int level) {
        if (!root)
            return;
        if (res.size() <= level)
            res.push_back({root->val});
        else
            res[level].push_back(root->val);
        helper(res, root->left, level + 1);
        helper(res, root->right, level + 1);
    }
};