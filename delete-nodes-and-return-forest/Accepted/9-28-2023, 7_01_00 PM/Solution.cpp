// https://leetcode.com/problems/delete-nodes-and-return-forest

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root)
            return {};
        vector<TreeNode*> res;
        helper(root, root, to_delete, res, false);
        return res;
    }

    void helper(TreeNode* root, TreeNode* parent, vector<int>& to_delete, vector<TreeNode*>& res, bool isSaved) {
        if (!root)
            return;
        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            parent->left = (parent->left == root)? NULL : parent->left;
            parent->right = (parent->right == root)? NULL : parent->right;
            helper(root->left, root->left, to_delete, res, false);
            helper(root->right, root->right, to_delete, res, false);
            return;
        }
        if (!isSaved) {
            res.push_back(root);
        }
        helper(root->left, root, to_delete, res, true);
        helper(root->right, root, to_delete, res, true);
    }
};