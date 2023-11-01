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
    unordered_map<int, int> m;
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        m.clear();
        helper(root);

        int cnt = 0;
        for (auto i : m) {
            if (cnt < i.second) {
                cnt = i.second;
                res = { i.first };
                continue;
            }
            else if (cnt == i.second) {
                res.push_back(i.first);
            }
        }
        
        return res;
    }

    void helper(TreeNode* root) {
        if (!root)
            return;
        m[root->val]++;
        helper(root->left);
        helper(root->right);
    }
};