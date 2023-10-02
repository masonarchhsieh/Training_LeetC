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
    vector<TreeNode*> v;
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root)
            return true;
        
        travelTree(root);
        int isNotCompleted = 0;
        for (auto i = 0 ; i < v.size(); i++)
            if (!v.at(i))
                isNotCompleted++;
            else if (isNotCompleted > 0)
                return false;
        return true;
    }

    void travelTree(TreeNode* root) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (!tmp)
                break;
            q.push(tmp->left);
            v.push_back(tmp->left);
            q.push(tmp->right);
            v.push_back(tmp->right);
        }
    }

};