// https://leetcode.com/problems/add-two-numbers-ii

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        return reverseList(helper(l1, l2));
    }

    ListNode* reverseList(ListNode *head) {
        ListNode *prev = NULL;

        while (head) {
            ListNode *nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    ListNode* helper(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        int carry = 0;

        while (l1 || l2 || carry != 0) {
            int n1 = (l1 != NULL)? l1->val : 0;
            int n2 = (l2 != NULL)? l2->val : 0;
            int digit = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;

            ListNode *node = new ListNode(digit);
            tail->next = node;
            tail = tail->next;

            l1 = (l1 != NULL)? l1->next : NULL;
            l2 = (l2 != NULL)? l2->next : NULL;
        }
        
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};