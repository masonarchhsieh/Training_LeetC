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
#include <algorithm>
class Solution {
    vector<vector<unsigned long long>> v;
public:
    int widthOfBinaryTree(TreeNode* root) {
        int max_width = 1;
        v.clear();
        travel(root, 0, 0);
        for (auto i = 1; i < v.size(); i++) {
            max_width = max(max_width, (int)(v[i].back() - v[i].front() + 1));
        }
        return max_width;
    }

    void travel(TreeNode* root, unsigned long long index, int level) {
        if (!root) {
            return;
        }
        if (v.size() <= level)
            v.push_back({});
        v[level].push_back(index);
        travel(root->left, index * 2L, level + 1);
        travel(root->right, index * 2L + 1, level + 1);
    }
};