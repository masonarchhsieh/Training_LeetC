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
    vector<int> res;
    unordered_map<int, int> m;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root)
            return {};
        res.clear();
        m.clear();
        int most_occ = 0;
        helper(root, most_occ);
        for (auto &i : m) {
            if (i.second == most_occ)
                res.push_back(i.first);
        }

        return res;
    }

    int helper(TreeNode* root, int& most_occ) {
        if (!root)
            return 0;
        int left_sum = helper(root->left, most_occ);
        int right_sum = helper(root->right, most_occ);
        m[root->val + left_sum + right_sum]++;
        most_occ = max(most_occ, m[root->val + left_sum + right_sum]);
        return root->val + left_sum + right_sum;
    }
};