// https://leetcode.com/problems/convert-bst-to-greater-tree

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
    vector<int> v;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return root;
        travelTree(root);
        sort(v.begin(), v.end());
        updateVal(root);

        return root;
    }

    void travelTree(TreeNode* root) {
        if (!root)
            return;
        travelTree(root->left);
        v.push_back(root->val);
        travelTree(root->right);
    }

    void updateVal(TreeNode* root) {
        if (!root)
            return;
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), root->val);
        root->val = accumulate(it, v.end(), 0);
        updateVal(root->left);
        updateVal(root->right);
    }
};