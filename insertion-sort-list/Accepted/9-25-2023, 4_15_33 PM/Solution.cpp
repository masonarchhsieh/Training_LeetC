// https://leetcode.com/problems/insertion-sort-list

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        int tmp = 0;
        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            for (ListNode* prev = head; prev != curr; prev = prev->next) {
                if (curr->val < prev->val) {
                    tmp = curr->val;
                    curr->val = prev->val;
                    prev->val = tmp;
                }
            }
        }
        return head;
    }
};