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
    vector<vector<int>> res;
public:
    void traverse(TreeNode* root, vector<int> &path, int targetSum) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            path.push_back(root->val);
            if (targetSum == root->val)
                res.push_back(path);
            path.pop_back();    //undo
            return;
        }
        path.push_back(root->val);
        traverse(root->left, path, targetSum - root->val);
        traverse(root->right, path, targetSum - root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        if (!root)
            return res;
        vector<int> path;
        traverse(root, path, targetSum);
        return res;
    }
};