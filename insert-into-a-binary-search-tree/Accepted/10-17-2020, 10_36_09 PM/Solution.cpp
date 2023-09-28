// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* t = new TreeNode(val);
            return t;
        }
        
        TreeNode* itr = root;
        while (itr != nullptr) {
            if (val < itr->val && itr->left != nullptr)
                itr = itr->left;
            else if (val > itr->val && itr->right != nullptr)
                itr = itr->right;
            else {
                TreeNode* t = new TreeNode(val);
                if (val < itr->val)
                    itr->left = t;
                else
                    itr->right = t;
                
                break;
            }
        }
        
        return root;
    }
};