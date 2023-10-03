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
    // the idea is either rob tree with depth : 0, 2, 4, 6, ..., or 1, 3, 5, 7, ...
    int rob(TreeNode* root) {
        pair<int, int> res = solve(root);
        return max(res.first, res.second);
    }

    pair<int, int> solve(TreeNode* root) {
        if (!root)
            return {0, 0};
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        return make_pair(root->val + left.second + right.second, 
                max(left.first, left.second) + max(right.first, right.second));
    }
};