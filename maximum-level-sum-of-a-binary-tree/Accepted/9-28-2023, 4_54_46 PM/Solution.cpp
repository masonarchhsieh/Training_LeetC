// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    vector<vector<int>> v;
public:
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return 0;
        int res = root->val;
        int _res = 1;
        travelTree(root, 0);
        for (auto i = 1; i < v.size(); i++) {
            int t = accumulate(v.at(i).begin(), v.at(i).end(), 0);
            if (res < t) {
                res = t;
                _res = i + 1;
            }
        }
        return _res;
    }

    void travelTree(TreeNode* root, int level) {
        if (!root)
            return;
        
        if (v.size() <= level) {
            vector<int> t = { root->val };
            v.push_back(t);
        } else {
            v[level].push_back(root->val);
        }
        travelTree(root->left, level + 1);
        travelTree(root->right, level + 1);
    }
};