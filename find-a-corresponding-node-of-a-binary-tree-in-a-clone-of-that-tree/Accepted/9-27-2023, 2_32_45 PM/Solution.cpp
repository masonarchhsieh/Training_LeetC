// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original || !cloned)
            return NULL;

        if (original == target) {
            return cloned;
        }
        
        TreeNode *left_node = getTargetCopy(original->left, cloned->left, target);
        TreeNode *right_node = getTargetCopy(original->right, cloned->right, target);

        if (left_node && left_node->val == target->val)
            return left_node;

        return right_node;
    }
};