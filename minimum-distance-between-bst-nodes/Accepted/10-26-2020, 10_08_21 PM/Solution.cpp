// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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
    int minDiffInBST(TreeNode* root) {
        vector<int> tree;
        helper(root, tree);
        
        int res = INT_MAX;
        sort(tree.begin(), tree.end());
        
        for (int i=1; i<tree.size(); i++) {
            res = (res < tree[i] - tree[i-1])? res : tree[i] - tree[i-1];
        }
        
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& tree) {
        if (root == NULL)
            return;
        helper(root->left, tree);
        tree.push_back(root->val);
        helper(root->right, tree);
    }
};