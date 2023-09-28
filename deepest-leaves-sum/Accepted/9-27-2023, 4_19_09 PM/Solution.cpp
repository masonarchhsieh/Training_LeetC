// https://leetcode.com/problems/deepest-leaves-sum

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

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first > p2.first;
}

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        int sum = 0;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            sum = 0;
            for (auto i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();

                sum += t->val;
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
        }

        return sum;
    }

    // int deepestLeavesSum(TreeNode* root) {
    //     if (!root)
    //         return 0;
    //     vector<pair<int, int>> v;
    //     travelTree(root, v, 0);
    //     sort(v.begin(), v.end(), compare);
    //     int sum = v[0].second;
    //     for (auto i = 1; i < v.size(); i++) {
    //         if (v[i].first == v[0].first) {
    //             sum += v[i].second;
    //             continue;
    //         }
    //         break;
    //     }
    //     return sum;
    // }

    // void travelTree(TreeNode* root, vector<pair<int,int>>& v, int level) {
    //     if (!root)
    //         return;
        
    //     if (!root->left && !root->right) {
    //         v.push_back(make_pair(level, root->val));
    //         return;
    //     }
    //     travelTree(root->left, v, level + 1);
    //     travelTree(root->right, v, level + 1);
    // }
};