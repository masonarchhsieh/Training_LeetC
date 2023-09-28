// https://leetcode.com/problems/n-ary-tree-preorder-traversal

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
    vector<int> preorder(Node* root) {
        if (!root)
            return {};
        
        vector<int> tree;
        
        tree.push_back(root->val);
        for (auto i = 0; i < root->children.size(); i++)
        {
            vector<int> temp = preorder(root->children[i]);
            tree.insert(tree.end(), temp.begin(), temp.end());
        }
        
        return tree;
    }
};