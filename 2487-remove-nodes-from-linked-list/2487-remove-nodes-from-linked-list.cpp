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
    ListNode* removeNodes(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *nxt = removeNodes(head->next);
        if (nxt && head->val < nxt->val) {
            return nxt;
        }
        head->next = nxt;
        return head;
    }
};