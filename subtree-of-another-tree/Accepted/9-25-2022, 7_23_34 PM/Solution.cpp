// https://leetcode.com/problems/subtree-of-another-tree

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        
        bool is_sub = false;
        is_sub = helper(root, subRoot);
        if (is_sub)
            return true;
        is_sub |= isSubtree(root->left, subRoot);
        is_sub |= isSubtree(root->right, subRoot);

        return is_sub;
    }
    
    
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if ((root && !subRoot) || (!root && subRoot))
            return false;
        if (!root && !subRoot)
            return true;
        if (root->val != subRoot->val)
            return false;
        
        bool is_sub = true;
        is_sub &= helper(root->left, subRoot->left);
        is_sub &= helper(root->right, subRoot->right);

        return is_sub;
    }
};