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
    unordered_set<string> _set;
public:
    string smallestFromLeaf(TreeNode* root) {
        helper(root, "");
        string res  = (_set.empty())? "" : *(_set.begin());
        for (auto i : _set)
            res = min(res, i);
        return res;
    }

    void helper(TreeNode *root, string s) {
        if (!root)
            return;
        s = 'a' + s;
        s[0] = 'a' + root->val;
        if (!root->left && !root->right) {
            _set.insert(s);
            return;
        }
        helper(root->left, s);
        helper(root->right, s);
    }
};