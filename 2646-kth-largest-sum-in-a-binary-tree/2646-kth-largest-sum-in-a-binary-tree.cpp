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
    vector<long long> level_sums;
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        travel(root, 0);
        sort(level_sums.begin(), level_sums.end());

        return (k > level_sums.size())? -1 : level_sums.at(level_sums.size() - k);
    }

    void travel(TreeNode* root, int level) {
        if (!root)
            return;
        if (level >= level_sums.size())
            level_sums.push_back(0);
        level_sums[level] += root->val;
        travel(root->left, level + 1);
        travel(root->right, level + 1);
    }
};