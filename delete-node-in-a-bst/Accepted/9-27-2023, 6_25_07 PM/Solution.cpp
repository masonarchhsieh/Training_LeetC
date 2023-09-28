// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        // delete the node with the same value of the key
        if (root->val == key) {
            // construct left tree
            return constructTree(root->left, root->right);
        }

        // search right
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        root->left = deleteNode(root->left, key);
        return root;
    }

    TreeNode* constructTree(TreeNode* t1, TreeNode* t2) {
        if (!t1)
            return t2;
        if (!t2)
            return t1;
        if (t1->val < t2->val) {
            t2->left = constructTree(t1, t2->left);
            return t2;
        }
        t1->left = constructTree(t1->left, t2);
        return t1;
    }
};