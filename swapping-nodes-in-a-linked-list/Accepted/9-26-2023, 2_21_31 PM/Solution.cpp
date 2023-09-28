// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode *node) {
        int l = 0;
        while (node) {
            node = node->next;
            l++;
        }
        return l;
    }

    ListNode* findNode(ListNode* head, int pos) {
        if (!head || pos <= 0)
            return head;
        while (head && pos > 1) {
            pos--;
            head = head->next;
        }

        return head;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        if (!head)
            return head;
        int length = findLength(head);
        ListNode *node1 = findNode(head, k);
        ListNode *node2 = findNode(head, length - k + 1);
        swapNode(node1, node2);

        return head;
    }

    void swapNode(ListNode *n1, ListNode *n2) {
        if (!n1 || !n2)
            return;
        swap(n1->val, n2->val);
    }
};