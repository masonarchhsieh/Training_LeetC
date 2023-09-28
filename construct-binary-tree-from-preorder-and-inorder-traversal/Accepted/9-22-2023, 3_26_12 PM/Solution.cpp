// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    int preInd = 0;
public:
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (start > end)
            return NULL;
        TreeNode* node = new TreeNode(preorder[preInd++]);
        int pos;
        for (auto i = start; i <= end; i++) {
            if (inorder[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left = createTree(preorder, inorder, start, pos - 1);
        node->right = createTree(preorder, inorder, pos + 1, end);
        return node;
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        if (preorder.size() != inorder.size())
            return NULL;
        return createTree(preorder, inorder, 0, preorder.size() - 1);
    }
};