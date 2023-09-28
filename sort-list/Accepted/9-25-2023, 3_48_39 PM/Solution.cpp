// https://leetcode.com/problems/sort-list

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
    ListNode* mergeLists(ListNode* first, ListNode* second) {
        if (first == NULL)
            return second;
        if (second == NULL)
            return first;
        if (first->val <= second->val) {
            first->next = mergeLists(first->next, second);
            return first;
        }

        second->next = mergeLists(first, second->next);
        return second;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        return mergeLists(l1, l2);
    }
};