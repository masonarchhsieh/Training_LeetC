// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

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
    vector<int> res;
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        travelTree(root1, res);
        travelTree(root2, res);
        sort(res.begin(), res.end());

        return res;
    }

    void travelTree(TreeNode* root, vector<int>& res) {
        if (!root)
            return;
        travelTree(root->left, res);
        res.push_back(root->val);
        travelTree(root->right, res);
    }
};