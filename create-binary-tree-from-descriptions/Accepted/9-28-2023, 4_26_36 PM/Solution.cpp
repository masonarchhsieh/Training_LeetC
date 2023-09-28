// https://leetcode.com/problems/create-binary-tree-from-descriptions

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> child_set;
        TreeNode* head = NULL;
        if (descriptions.size() == 0)
            return head;
        for (auto i = 0; i < descriptions.size(); i++) {
            bool found = false, found_child = false;
            TreeNode* child;
            TreeNode* parent;
            if (m.find(descriptions[i][1]) != m.end()) {
                child = m[descriptions[i][1]];
            } else {
                child = new TreeNode(descriptions[i][1]);
                m[descriptions[i][1]] = child;
            }
            child_set.insert(child->val);
            if (m.find(descriptions[i][0]) != m.end()) {
                parent = m[descriptions[i][0]];
            } else {
                parent = new TreeNode(descriptions[i][0]);
                m[descriptions[i][0]] = parent;
            }
            // left child
            if (descriptions[i][2] == 1) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        for (auto &i : descriptions) {
            if (child_set.find(i[0]) == child_set.end()) {
                head = m[i[0]];
                break;
            }
        }
        return head;
    }
};