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
    // vector<int> v;
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* t;

        int res = INT_MIN, level = 1, res_level;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            int sum = 0;
            while (s-- > 0) {
                t = q.front();  q.pop();
                sum += t->val;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            if (sum > res) {
                res = sum;
                res_level = level;
            }
            level++;
        }
        return res_level;
    }

    // Recursion method:
    // int maxLevelSum(TreeNode* root) {
    //     if (!root)
    //         return 0;
    //     travelTree(root, 0);
    //     return (int) (max_element(v.begin(), v.end()) - v.begin()) + 1;
    // }

    // void travelTree(TreeNode* root, int level) {
    //     if (!root)
    //         return;
        
    //     if (v.size() <= level) {
    //         v.push_back(root->val);
    //     } else {
    //         v[level] += root->val;
    //     }
    //     travelTree(root->left, level + 1);
    //     travelTree(root->right, level + 1);
    // }
};