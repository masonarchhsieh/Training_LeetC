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
    bool isEven(const int& i) {
        return i % 2 == 0;
    }
    bool isEvenOddTree(TreeNode* root) {
        v.clear();
        if (!root)
            return true;
        travel(root, 0);

        for (auto i = 0; i < v.size(); i++) {
            if (isEven(v[i][0]) == isEven(i))
                return false;
            for (auto j = 1; j < v[i].size(); j++) {
                // // even-indexed level
                if (i % 2 == 0) {
                    if ((isEven(v[i][j]) == isEven(i)) || v[i][j] <= v[i][j-1])
                        return false;
                }
                // odd-indexed level
                else {
                    if ((isEven(v[i][j]) == isEven(i)) || v[i][j] >= v[i][j-1])
                        return false;
                }
            }
        }
        return true;
    }

    void travel(TreeNode* root, int level) {
        if (!root)
            return;
        if (level >= v.size())
            v.push_back({root->val});
        else
            v[level].push_back(root->val);
        travel(root->left, level + 1);
        travel(root->right, level + 1);
    }
};