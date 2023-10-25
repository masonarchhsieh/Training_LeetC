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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t;

        while (!q.empty()) {
            int s = q.size();
            vector<int> tmp;
            for (auto i = 0; i < s; i++) {
                t = q.front();
                if (t->right)
                    q.push(t->right);
                if (t->left)
                    q.push(t->left);
                tmp.push_back(t->val);
                q.pop();
            }
            res.push_back(tmp.front());
        }

        return res;
    }

    // Recursion Method:
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> res;
    //     constructView(res, root, 0);
    //     return res;
    // }

    // void constructView(vector<int>& v, TreeNode* root, int level) {
    //     if (!root)
    //         return;
    //     if (level >= v.size())
    //         v.push_back(root->val);
    //     constructView(v, root->right, level + 1);
    //     constructView(v, root->left, level + 1);
    // }
};