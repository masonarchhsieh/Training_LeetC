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
    vector<ListNode*> v;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next)
            return NULL;
        
        ListNode *prev = NULL, *cur = head, *b_prev = NULL;
        while (cur) {
            prev = b_prev;
            b_prev = b_prev == NULL ? b_prev : b_prev->next;
            if (--n == 0) {
                b_prev = head;
            }
            cur = cur->next;
        }

        if (!prev)
            return head->next;
        prev->next = b_prev->next;
        return head;
    }
};