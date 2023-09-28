// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
    vector<int> v;
    int pos = -1;
public:
    BSTIterator(TreeNode* root) {
        v.clear();
        constructTree(root);
        pos = 0;
    }

    void constructTree(TreeNode* root) {
        if (!root)
            return;
        constructTree(root->left);
        v.push_back(root->val);
        constructTree(root->right);
    }
    
    int next() {
        return v.at(pos++);
    }
    
    bool hasNext() {
        return pos < v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */