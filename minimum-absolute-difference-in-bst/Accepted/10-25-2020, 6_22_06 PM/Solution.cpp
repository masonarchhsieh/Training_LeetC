// https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    int getMinimumDifference(TreeNode* root) {
        vector<int> tree;
        helper(root, tree);
        
        sort(tree.begin(), tree.end());
        int res = INT_MAX;
        for (int i=1; i<tree.size(); i++) {
            res = (abs(tree[i] - tree[i-1]) < res)? abs(tree[i] - tree[i-1]) : res;
            
        }
        
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& tree) {
        if (root == NULL)
            return;
        
        tree.push_back(root->val);
        helper(root->left, tree);
        helper(root->right, tree);
        
    }
};