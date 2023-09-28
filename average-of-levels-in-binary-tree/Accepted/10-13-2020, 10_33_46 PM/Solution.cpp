// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> temp;
        helper(root, temp, 0);
        
        vector<double> res;
        for (int i=0; i<temp.size(); i++) {
            double te = 0.0;
            for (int j=0; j<temp[i].size(); j++) {
                te += (double) temp[i][j];
            }
            double average = (double) (te / (double) temp[i].size());
            res.push_back(average);
        }
        
        return res;
    }
    
    void helper(TreeNode* root, vector<vector<int>>& list, int level) {
        if (root == nullptr)
            return;
        
        if (list.size() <= level) {
            vector<int> temp;
            temp.push_back(root->val);
            list.push_back(temp);
        } else {
            list[level].push_back(root->val);
        }
        
        if (root->left != nullptr)
            helper(root->left, list, level + 1);
        if (root->right != nullptr)
            helper(root->right, list, level + 1);

    }
};