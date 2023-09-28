// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        
        getLevel(root, res, 0);
        std::reverse(res.begin(),res.end());
        return res;
    }
    
    void getLevel(TreeNode* root, vector<vector<int>>& lists, int level)
    {
        if (root == nullptr)
            return;
        
        if (lists.size() <= level)
        {
            vector<int> temp;
            temp.push_back(root->val);
            lists.push_back(temp);
        }
        else
            lists[level].push_back(root->val);
        
        if (root->left != nullptr)
            getLevel(root->left, lists, level + 1);
        
        if (root->right != nullptr)
            getLevel(root->right, lists, level + 1); 
    }
    
};