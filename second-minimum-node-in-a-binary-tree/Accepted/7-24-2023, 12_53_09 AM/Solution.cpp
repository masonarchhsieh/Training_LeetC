// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

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
    vector<int> list;
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root)
            return -1;
        helper(root);
        sort(list.begin(), list.end());
        vector<int>::iterator it;
        it = unique(list.begin(), list.end());
        return (it == list.begin() + 1)? -1 : list[1];
    }

    void helper(TreeNode* root) {
        if (!root)
            return;
        helper(root->left);
        list.push_back(root->val);
        helper(root->right);
    }
};