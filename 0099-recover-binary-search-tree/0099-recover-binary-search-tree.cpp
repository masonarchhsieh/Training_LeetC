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
    TreeNode* vic1, *vic2, *pre;
public:
    void recoverTree(TreeNode* root) {
        if (!root)
            return;
        pre = new TreeNode(INT_MIN);
        inorderTravel(root);
        swap(vic1->val, vic2->val);
    }

    void inorderTravel(TreeNode* root) {
        if (!root)
            return;
        inorderTravel(root->left);
        if (!vic1 && root->val < pre->val)
            vic1 = pre;
        if (vic1 && root->val < pre->val)
            vic2 = root;
        pre = root;
        inorderTravel(root->right);
    }
};