// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree

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
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        pair<int, int> res = helper(root, cnt);

        return cnt;
    }

    pair<int, int> helper(TreeNode* root, int &cnt) {
        if (!root)
            return {0, 0};
        pair p = make_pair(1, root->val);
        if (!root->left && !root->right) {
            cnt++;
            return p;
        }
        if (root->left) {
            pair tmp_l = helper(root->left, cnt);
            p.first += tmp_l.first;
            p.second += tmp_l.second;
        }
        if (root->right) {
            pair tmp_r = helper(root->right, cnt);
            p.first += tmp_r.first;
            p.second += tmp_r.second;
        }
        
        if (p.second / p.first == root->val) {
            cnt++;
        }
        return p;
    }
};