// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

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
    string rl;
public:
    int dfs(TreeNode* node, bool left, int depth) {
        return node == nullptr ? depth : 
            max(dfs(left ? node->left : node->right, !left, depth + 1), 
               dfs(left ? node->right : node->left, left, 0));    
    }
    
    int longestZigZag(TreeNode* root) {
        return max(dfs(root, true, -1), dfs(root, false, -1));
    }

};