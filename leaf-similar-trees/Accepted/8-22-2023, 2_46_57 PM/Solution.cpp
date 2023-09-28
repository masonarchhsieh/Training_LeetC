// https://leetcode.com/problems/leaf-similar-trees

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
    vector<int> r1, r2;
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        helper(r1, root1);
        helper(r2, root2);

        if (r1.size() != r2.size())
            return false;
        for (auto i = 0; i < r1.size(); i++) {
            if (r1[i] != r2[i])
                return false;
        }

        return true;
    }

    void helper(vector<int> &l, TreeNode *root) {
        if (!root)
            return;
        
        if (!root->left && !root->right)
            l.push_back(root->val);
        
        helper(l, root->left);
        helper(l, root->right);
    }
};