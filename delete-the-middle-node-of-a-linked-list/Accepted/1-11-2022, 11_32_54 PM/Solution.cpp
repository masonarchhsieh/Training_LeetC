// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if (fast->next == NULL)
            return NULL;
        fast = fast->next;
        if (fast->next == NULL)
        {
            head->next = NULL;
            return head;
        }
        fast = fast->next;
        bool flip = false;
        while (fast != NULL) {
            if (fast->next == NULL)
            {
                slow->next = slow->next->next; 
                flip = true;
                break;
            }
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
        }
        
        if (!flip) {
            slow->next = slow->next->next; 
        }
            
        return head;
    }
};