// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next)
            return nullptr;

        ListNode *prev = nullptr, *curr = head, *b_prev = nullptr;
        
        while (curr) {
            prev = b_prev;
            b_prev = b_prev == nullptr ? b_prev : b_prev->next;
            if (--n == 0)
                b_prev = head;
            curr = curr->next;
        }
        
        if (!prev)
            return head->next;
        prev->next = b_prev->next;
        return head;
    }
};