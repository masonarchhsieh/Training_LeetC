// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        if (!head || !head->next)
            return false;
        slow = head;
        fast = head->next;

        while (fast) {
            if (slow == fast)
                return true;
            slow = slow->next;
            if (!fast->next)
                return false;
            fast = fast->next->next;
        }

        return false;
    }
};