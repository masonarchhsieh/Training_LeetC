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
    vector<int> largestValues(TreeNode* root) {
        v.clear();
        helper(root, 0);
        return v;
    }

    void helper(TreeNode* root, int level) {
        if (!root)
            return;
        if (v.size() <= level)
            v.push_back(root->val);
        else
            v[level] = max(v[level], root->val);
        helper(root->left, level + 1);
        helper(root->right, level + 1);
    }
};