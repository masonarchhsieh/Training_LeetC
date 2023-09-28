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
        for (int i=0; i<tree.size()-1; i++) {
            for (int j=i+1; j<tree.size(); j++) {
                res = (abs(tree[i] - tree[j]) < res)? abs(tree[i] - tree[j]) : res;
            }
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