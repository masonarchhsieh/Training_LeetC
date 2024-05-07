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
    ListNode* doubleIt(ListNode* head) {
        ListNode *res = helper(head);
        if (res && res->val >= 10) {
            ListNode *node = new ListNode(res->val / 10, res);
            res->val %= 10;
            res = node;
        }
        
        return res;
    }

    ListNode *helper(ListNode *head) {
        if (!head)
            return head;      
        head->val *= 2;
        if (!head->next)
            return head;
        ListNode *nxt = helper(head->next);
        if (nxt->val >= 10) {
            head->val += nxt->val / 10;
            nxt->val = nxt->val % 10;
        }
        return head;
    }
};