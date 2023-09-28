// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return divide_and_conquer(nums, 0, nums.size() - 1);
    }

    TreeNode* divide_and_conquer(vector<int>& nums, int left, int right) {
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        return new TreeNode(nums[mid], 
            divide_and_conquer(nums, left, mid - 1),
            divide_and_conquer(nums, mid + 1, right)
            );
    }

};