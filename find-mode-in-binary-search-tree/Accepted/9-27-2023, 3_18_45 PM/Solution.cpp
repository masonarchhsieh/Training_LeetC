// https://leetcode.com/problems/find-mode-in-binary-search-tree

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
        int max_occ = 0;
        travelTree(root);

        for (auto i : m)
            if (i.second > max_occ)
                max_occ = i.second;
        for (auto i : m)
            if (i.second == max_occ)
                res.push_back(i.first);

        return res;
    }

    void travelTree(TreeNode* root) {
        if (!root)
            return;
        m[root->val]++;
        travelTree(root->left);
        travelTree(root->right);
    }
};