// https://leetcode.com/problems/increasing-order-search-tree

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
    vector<TreeNode*> list;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root)
            return NULL;
        inOrder(root);
        list.push_back(NULL);
        for (int i = 1; i < list.size(); i++) {
            list[i - 1]->right = list[i];
            list[i - 1]->left = NULL;
        }


        return list[0];
    }

    void inOrder(TreeNode *root) {
        if (!root)
            return;
        
        inOrder(root->left);
        list.push_back(root);
        inOrder(root->right);
    }
};