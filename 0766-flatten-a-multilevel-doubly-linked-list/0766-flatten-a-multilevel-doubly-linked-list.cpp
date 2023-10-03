/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    vector<Node*> v;
public:
    Node* flatten(Node* head) {
        if (!head)
            return head;

        travel(head);
        v[0]->child = NULL;
        v[0]->prev = 0;
        for (auto i = 1; i < v.size(); i++) {
            v[i-1]->next = v[i];
            v[i]->prev = v[i-1];
            v[i]->child = NULL;
        }
        v[v.size() - 1]->next = NULL;

        return v[0];
    }

    void travel(Node* head) {
        if (!head)
            return;
        v.push_back(head);
        travel(head->child);
        travel(head->next);
    }
};