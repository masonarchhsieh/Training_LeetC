// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;
        int res = 0;
        travelTree(root, res, root->val);
        return res;
    }

    void travelTree(TreeNode* root, int& n_good, int cur_max) {
        if (!root)
            return;
        if (root->val >= cur_max)
            n_good++;

        travelTree(root->left, n_good, max(cur_max, root->val));
        travelTree(root->right, n_good, max(cur_max, root->val));
    }
};