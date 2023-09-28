// https://leetcode.com/problems/n-ary-tree-postorder-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root)
            return {};
        
        vector<int> tree;
        for (auto i = 0; i < root->children.size(); i++) {
            vector<int> tmp = postorder(root->children[i]);
            tree.insert(tree.end(), tmp.begin(), tmp.end());
        }
        tree.push_back(root->val);

        return tree;
    }
};