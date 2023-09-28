// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder.begin(), preorder.end());
    }
    
    
    TreeNode* helper(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin == end)
            return nullptr;
        
        auto node = new TreeNode(*begin);
        auto bound = upper_bound(begin+1, end, *begin);
        
        node->left = helper(begin+1, bound);
        node->right = helper(bound, end);
        return node;
    }
};