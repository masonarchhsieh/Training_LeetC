// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    int sumNumbers(TreeNode* root) {
        vector<int> tree;
        int res = 0;
        if (root != nullptr)
            helper(root, tree, "");
        
        for (int i=0; i<tree.size(); i++)
            res += tree[i];
        
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& tree, string prev) {
        
        prev = prev + std::to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            int rtl = std::stoi(prev);
            tree.push_back(rtl);
        }
        
        if (root->left != nullptr) {
            helper(root->left, tree, prev);
        }
        if (root->right != nullptr) {
            helper(root->right, tree, prev);
        }
    }
};