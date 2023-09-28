// https://leetcode.com/problems/unique-binary-search-trees-ii

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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> res;

        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        for (auto i = start; i <= end; i++) {
            vector<TreeNode*> leftTree = helper(start, i - 1);
            vector<TreeNode*> rightTree = helper(i + 1, end);

            for (auto l : leftTree) {
                for (auto r : rightTree) {
                    TreeNode *root = new TreeNode(i, l, r);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};