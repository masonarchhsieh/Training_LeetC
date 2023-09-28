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
    set<pair<TreeNode*, TreeNode*>> s;
public:
    void traverse(TreeNode* root, vector<TreeNode*> &path, int targetSum) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            path.push_back(root);
            for (auto i = 0; i < path.size(); i++) {
                long long _sum = 0;
                for (auto j = i; j < path.size(); j++) {
                    _sum += path[j]->val;
                    if (_sum == targetSum) {
                        s.insert(make_pair(path[i], path[j]));
                    }
                }
            }
            path.pop_back();    //undo
            return;
        }
        path.push_back(root);
        traverse(root->left, path, targetSum);
        traverse(root->right, path, targetSum);
        path.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        s.clear();
        if (!root)
            return 0;
        vector<TreeNode*> path;
        traverse(root, path, targetSum);
        return s.size();
    }
};