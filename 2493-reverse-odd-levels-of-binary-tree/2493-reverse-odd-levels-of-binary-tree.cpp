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
    vector<vector<TreeNode*>> v;
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        travel(root, 0);
        update();
        return root;
    }

    void update() {
        for (auto &i : v) {
            for (auto j = 0; j < i.size() / 2; j++) {
                swap(i[j]->val, i[i.size() - 1 - j]->val);
            }
        }
    }

    void travel(TreeNode* root, int level) {
        if (!root)
            return;
        if (level % 2 == 1) {
            if (v.size() <= (level / 2))
                v.push_back({root});
            else
                v[level/2].push_back(root);
        }
        travel(root->left, level + 1);
        travel(root->right, level + 1);
    }
};