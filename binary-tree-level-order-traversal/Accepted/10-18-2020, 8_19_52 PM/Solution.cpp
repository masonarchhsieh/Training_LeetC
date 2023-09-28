// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res, 0);
        
        return res;
    }
    
    void helper(TreeNode* root, vector<vector<int>>& lists, int level) {
        if (root == nullptr)
            return;
        
        if (lists.size() <= level) {
            vector<int> temp;
            temp.push_back(root->val);
            lists.push_back(temp);
        } else {
            lists[level].push_back(root->val);
        }
        
        helper(root->left, lists, level + 1);
        helper(root->right, lists, level + 1);
    }
};