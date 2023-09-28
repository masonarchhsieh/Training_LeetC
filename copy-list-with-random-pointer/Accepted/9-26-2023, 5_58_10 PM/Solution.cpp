// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> m;
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        Node *node = new Node(head->val);
        m.insert(make_pair(head, node));
        node->next = copyRandomList(head->next);
         
        if (head->random) {
            if (m.find(head->random) != m.end()) {
                node->random = m[head->random];
            }
        }
        return node;
    }

};