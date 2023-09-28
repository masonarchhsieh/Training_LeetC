// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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

static bool Pred(ListNode *l1, ListNode *l2) {
     return (l1->val == l2->val);
 }
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *res = head, *itr = head->next;
        while (itr) {
            if (res->val != itr->val) {
                res->next = itr;
                res = res->next;
            } 
            else {
                res->next = nullptr;
            }
            itr = itr->next;
        }

        return head;
    }
};