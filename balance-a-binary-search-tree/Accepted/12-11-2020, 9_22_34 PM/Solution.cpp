// https://leetcode.com/problems/balance-a-binary-search-tree

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
    vector<TreeNode*> tree;
public:
    TreeNode* balanceBST(TreeNode* root) {
        buildTree(root);
        return construct(0, tree.size());
    }
    
    TreeNode* construct(int l, int r) {
        if (l >= r)
            return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = tree[mid];
        
        root->left = construct(l, mid);
        root->right = construct(mid+1, r);
        
        return root;
    }
       
    void buildTree(TreeNode* root) {
        if (!root)
            return;
        
        buildTree(root->left);
        tree.push_back(root);
        buildTree(root->right);
    }
    
};