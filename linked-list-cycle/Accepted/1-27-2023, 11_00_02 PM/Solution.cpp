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
        ListNode *slow = head, *fast = head;
        
        if (!head || head->next == NULL)
            return false;
        
        fast = head->next->next;
        while (fast != NULL && slow != NULL) {
            if (slow == fast)
                return true;
            if (fast->next == NULL)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
};