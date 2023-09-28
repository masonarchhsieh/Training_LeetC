// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tree;
        
        help(tree, root);
        sort(tree.begin(), tree.end());
        return tree[k-1];
        
    }
    
    void help(vector<int>& tree, TreeNode* root) {
        if (!root)
            return;
        tree.push_back(root->val);
        help(tree, root->left);
        help(tree, root->right);
    }
};