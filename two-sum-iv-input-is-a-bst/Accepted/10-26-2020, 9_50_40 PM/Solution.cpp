// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    bool findTarget(TreeNode* root, int k) {
        vector<int> tree;
        helper(root, tree);
        
        for (int i=0; i<tree.size()-1; i++) {
            for (int j=i+1; j<tree.size(); j++) {
                if (tree[i] + tree[j] == k)
                    return true;
            }
        }
        
        return false;
    }
    
    void helper(TreeNode* root, vector<int>& tree) {
        if (root == NULL)
            return;
        
        tree.push_back(root->val);
        helper(root->left, tree);
        helper(root->right, tree);     
    }
};