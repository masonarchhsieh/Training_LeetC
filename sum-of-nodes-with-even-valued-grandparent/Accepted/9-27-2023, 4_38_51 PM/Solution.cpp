// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent

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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        travelTree(root, root->val % 2 == 0, sum, 0);
        return sum;
    }

    void travelTree(TreeNode* root, bool isGrandParentEven, int& sum, int level) {
        if (!root)
            return;
        if (!root->left && !root->right)
            return;
        if (isGrandParentEven && level > 0) {
            if (root->left)
                sum += root->left->val;
            if (root->right)
                sum += root->right->val;
        }
        travelTree(root->left, root->val % 2 == 0, sum, level + 1);
        travelTree(root->right, root->val % 2 == 0, sum, level + 1);
    }
};