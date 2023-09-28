// https://leetcode.com/problems/leaf-similar-trees

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1, leafs2;
        getLeafs(root1, leafs1);
        getLeafs(root2, leafs2);
        
        int sum1 = 0, sum2 = 0;
        for (int i=0; i<leafs1.size(); i++)
            sum1 += leafs1[i];
        for (int i=0; i<leafs2.size(); i++)
            sum2 += leafs2[i];
        
        return leafs1 == leafs2;
    }
    
    void getLeafs(TreeNode* root, vector<int>& leafs) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            leafs.push_back(root->val);
        
        getLeafs(root->left, leafs);
        getLeafs(root->right, leafs);
    }
};