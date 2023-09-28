// https://leetcode.com/problems/complete-binary-tree-inserter

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
class CBTInserter {
    vector<TreeNode*> v;
public:
    CBTInserter(TreeNode* root) {
        v.clear();
        v.push_back(root);
        for (auto i = 0; i < v.size(); i++) {
            if (v[i]->left)
                v.push_back(v[i]->left);
            if (v[i]->right)
                v.push_back(v[i]->right);
        }
    }
    
    int insert(int val) {
        int N = v.size();
        TreeNode *t = new TreeNode(val);
        v.push_back(t);
        // left node
        if (N % 2) {
            v[(N - 1) / 2]->left = t;
        } else {
            v[(N - 1) / 2]->right = t;
        }
        return v[(N - 1) / 2]->val;
    }
    
    TreeNode* get_root() {
        return v[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */