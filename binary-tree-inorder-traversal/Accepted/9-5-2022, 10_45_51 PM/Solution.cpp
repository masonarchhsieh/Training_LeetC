// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return vector<int>{};
        
        vector<int> list;
        vector<int> list_left = inorderTraversal(root->left);
        vector <int> list_right = inorderTraversal(root->right);
        
        list.insert(list.end(), list_left.begin(), list_left.end());
        list.push_back(root->val);
        list.insert(list.end(), list_right.begin(), list_right.end());
        
        return list;
    }
};