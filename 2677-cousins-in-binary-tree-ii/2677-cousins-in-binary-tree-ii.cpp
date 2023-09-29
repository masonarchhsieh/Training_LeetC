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
    unordered_map<TreeNode*, int> subtree_sum;     // user parent node as key & store the sum of its childs values
    unordered_map<int, int> level_sum_m;            // store the sum of the each level

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        travelTree(root, 0);
        updateTree(root, root, 0);
        return root;
    }

    void travelTree(TreeNode* root, int level) {
        if (!root)
            return;
        if (root->left) {
            subtree_sum[root] += root->left->val;
            level_sum_m[level + 1] += root->left->val;
        }
        if (root->right) {
            subtree_sum[root] += root->right->val;
            level_sum_m[level + 1] += root->right->val;
        }
        travelTree(root->left, level + 1);
        travelTree(root->right, level + 1);
    }

    void updateTree(TreeNode* itr, TreeNode* parent, int level) {
        if (!parent || !itr)
            return;
        itr->val = (level < 2)? 0 : level_sum_m[level] - subtree_sum[parent];
        updateTree(itr->left, itr, level + 1);
        updateTree(itr->right, itr, level + 1);
    }

};