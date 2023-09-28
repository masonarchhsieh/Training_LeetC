// https://leetcode.com/problems/maximum-binary-tree

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, nums.begin(), nums.end());       
    }
    
    TreeNode* construct(vector<int>& nums, vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin >= end)
            return NULL;
                
        vector<int>::iterator max_pos;
        max_pos = begin;
        for (vector<int>::iterator it = begin+1; it < end; it++) {
            if (*max_pos < *it)
                max_pos = it;
        }
        
        TreeNode *temp = new TreeNode(*max_pos);
        temp->left = construct(nums, begin, max_pos);
        temp->right = construct(nums, max_pos+1, end);
        
        return temp;
    }
};