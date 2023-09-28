// https://leetcode.com/problems/binary-tree-paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> tree;
        vector<string> res;
        helper(root, res, "");
        
        return res;
        
    }
    
    void helper(TreeNode* root, vector<string>& list, string prev) {       
        if (root != nullptr) {
            string temp = prev + std::to_string(root->val);
        
            if (root->left != nullptr) {
                helper(root->left, list, temp + "->");
            }

            if (root->right != nullptr) {
                helper(root->right, list, temp + "->");
            }

            if (root->left == nullptr && root->right == nullptr) {
                list.push_back(temp);
            }
        }
    }
};