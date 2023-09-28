// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> t;
        helper(root, t, 0);
        vector<double> res;
        for (auto i = 0; i < t.size(); i++) {
            double te = 0.0;
            for (auto j : t[i]) {
                te += (double) j;
            }
            res.push_back(te / t[i].size());
        }

        return res;
    }

    void helper(TreeNode* root, vector<vector<int>> &t, int level) {
        if (!root)
            return;
        if (t.size() <= level) {
            vector<int> tmp = { root->val };
            t.push_back(tmp);
        } else {
            t[level].push_back(root->val);
        }
        if (root->left)
            helper(root->left, t, level + 1);
        if (root->right)
            helper(root->right, t, level + 1);
    }
};