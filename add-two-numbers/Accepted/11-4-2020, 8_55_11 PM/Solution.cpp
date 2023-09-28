// https://leetcode.com/problems/add-two-numbers

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
        ListNode* head = new ListNode(0, 0);
        ListNode* itr = head;;

        helper(itr, l1, l2, 0);
        head = head->next;
        return head;
    }
    
    void helper(ListNode* itr, ListNode* l1, ListNode* l2, int carry) {
        int l1d = (l1 == NULL)? 0 : l1->val;
        int l2d = (l2 == NULL)? 0 : l2->val;
        int v = (l1d + l2d + carry) % 10;
        carry = (l1d + l2d + carry >= 10)? 1 : 0; 
        
        if (l1 == NULL && l2 == NULL) {
            if (v != 0) {
                ListNode* temp = new ListNode(v);
                itr->next = temp;
            }
            return;
        }
        
        if (l1 != NULL && l2 != NULL) {
            ListNode* temp = new ListNode(v);
            itr->next = temp;
            helper(itr->next, l1->next, l2->next, carry);
        }
        else if (l1 == NULL) {
            ListNode* temp = new ListNode(v);
            itr->next = temp;
            helper(itr->next, l1, l2->next, carry);
        }
        else if (l2 == NULL) {
            ListNode* temp = new ListNode(v);
            itr->next = temp;
            helper(itr->next, l1->next, l2, carry);
        }
    }
};