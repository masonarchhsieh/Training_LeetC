// https://leetcode.com/problems/merge-nodes-in-between-zeros

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
    ListNode* mergeNodes(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next)
            return NULL;
        ListNode *itr = head->next;
        ListNode *pre = itr;
        ListNode *new_head = NULL;
        int t = 0;
        while (itr) {
            if (itr->val == 0) {
                ListNode *node = new ListNode(t);
                pre->next = node;
                if (new_head == NULL)
                    new_head = node;
                pre = pre->next;
                t = 0;
            }
            else {
                t += itr->val;
            }
            itr = itr->next;
        }


        return new_head;
    }
};