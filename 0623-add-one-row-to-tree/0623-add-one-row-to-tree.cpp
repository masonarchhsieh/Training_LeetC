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
    vector<TreeNode*> v;
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root)
            return new TreeNode(val);
        if (depth == 1)
            return new TreeNode(val, root, NULL);

        helper(root, root, 1, val, depth);
        return root;
    }
    void helper(TreeNode* root, TreeNode* parent, int level, int val, int depth) {
        if (!root && level < depth)
            return;
        if (level < depth) {
            helper(root->left, root, level + 1, val, depth);
            helper(root->right, root, level + 1, val, depth);
            return;
        }
        
        TreeNode* node;
        if (parent->left == root) {
            node = new TreeNode(val, root, NULL);
            parent->left = node;
        } else {
            node = new TreeNode(val, NULL, root);
            parent->right = node;
        }
    }
};