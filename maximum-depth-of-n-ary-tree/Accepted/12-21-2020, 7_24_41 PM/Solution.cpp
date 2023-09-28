// https://leetcode.com/problems/maximum-depth-of-n-ary-tree

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
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        if ((root->children).size() == 0)
            return 1;
        
        int maxHeight = 1;
        for (int i=0; i<(root->children).size(); i++) {
            maxHeight = max(1 + maxDepth((root->children)[i]), maxHeight);
        }
        
        return maxHeight;
        
    }
};