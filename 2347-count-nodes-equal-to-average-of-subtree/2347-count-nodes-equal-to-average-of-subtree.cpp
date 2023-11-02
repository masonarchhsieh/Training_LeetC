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
    int res;
public:
    int averageOfSubtree(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }

    pair<int, int> helper(TreeNode* root) {
        pair<int, int> p {0, 0};
        if (!root)
            return p;
        p = { root->val, 1 };
        pair<int, int> p_l = helper(root->left), p_r = helper(root->right);
        p.first += p_l.first + p_r.first;
        p.second += p_l.second + p_r.second;
        res += (p.first / p.second == root->val);
        return p;
    }
};