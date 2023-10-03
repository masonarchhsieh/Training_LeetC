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
    vector<vector<string>> res;
public:
    vector<vector<string>> printTree(TreeNode* root) {
        res.clear();
        if (!root)
            return {};
        int height = Height(root);
        int width = pow(2, height) - 1;
        
        res.assign(height, vector<string>(width, ""));
        helper(root, 0, width / 2, width / 2);

        return res;
    }

    int Height(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(Height(root->left), Height(root->right));
    }

    void helper(TreeNode* root, int level, int pos, int width) {
        if (!root)
            return;
        
        res[level][pos] = to_string(root->val);

        helper(root->left, level + 1, (pos - 1) - width / 2, width / 2);
        helper(root->right, level + 1, (pos + 1) + width / 2, width / 2);
    }
};