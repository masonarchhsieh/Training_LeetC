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
class FindElements {
    unordered_set<int> s;
public:
    FindElements(TreeNode* root) {
        if (!root)
            return;
        
        root->val = 0;
        s.insert(0);
        updateTree(root);
    }

    void updateTree(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            root->left->val = root->val * 2 + 1;
            s.insert(root->left->val);
        }
        if (root->right) {
            root->right->val = root->val * 2 + 2;
            s.insert(root->right->val);
        }
        updateTree(root->left);
        updateTree(root->right);
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */