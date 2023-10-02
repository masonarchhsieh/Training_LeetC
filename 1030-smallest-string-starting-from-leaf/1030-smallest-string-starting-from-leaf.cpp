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
    vector<string> v;
public:
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        buildTree(root, path);
        string res;
        bool hasSet = false;
        for (auto &i : v) {
            reverse(i.begin(), i.end());
            if (res > i || !hasSet) {
                hasSet = true;
                res = i;
            }
        }

        return res;
    }

    void buildTree(TreeNode* root, string& path) {
        if (!root)
            return;
        
        char c = 'a' + root->val;
        path.push_back(c);
        if (root->left)
            buildTree(root->left, path);
        if (!root->left && !root->right) {
            v.push_back(path);
            return;
        }
        if (root->left)
            path.pop_back();
        if (root->right) {
            buildTree(root->right, path);
            path.pop_back();
        }
    }
};