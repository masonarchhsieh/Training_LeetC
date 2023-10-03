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
    int distributeCoins(TreeNode* root) {
        if (!root)
            return 0;
        int res = 0;
        solve(root, res);
        return res;
    }

    int solve(TreeNode* root, int& res) {
        if (!root)
            return 0;
        int t_left = solve(root->left, res);
        int t_right = solve(root->right, res);

        res += abs(t_left) + abs(t_right);
        return t_left + t_right + root->val - 1;
    }
};