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
            
            slow = slow->next;
            if (fast->next != NULL)
                fast = fast->next->next;
            else
                break;
        }
        
        return false;
    }
};