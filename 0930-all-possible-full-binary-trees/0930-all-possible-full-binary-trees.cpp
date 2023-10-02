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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n == 1)
            return { new TreeNode(0) };
        vector<TreeNode*> trees;
        n--;
        vector<TreeNode*> leftT, rightT;
        for (auto i = 1; i < n; i += 2) {
            leftT = allPossibleFBT(i);
            rightT = allPossibleFBT(n - i);
            for (TreeNode* left_node : leftT) {
                for (TreeNode* right_node : rightT) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left_node;
                    root->right = right_node;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};