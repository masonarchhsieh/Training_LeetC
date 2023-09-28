// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return NULL;
        
        Node *head = root;
        queue<Node*> qtree;
        qtree.push(root);
        
        while (!qtree.empty()) {
            int size = qtree.size();
            for (int i=0; i<size; i++) {
                auto node = qtree.front();
                qtree.pop();
                if (i == size - 1)
                    node->next = NULL;
                else
                    node->next = qtree.front();
            
                if (node->left)
                    qtree.push(node->left);
                if (node->right)
                    qtree.push(node->right);
            }
        }
        
        return head;
    }
};