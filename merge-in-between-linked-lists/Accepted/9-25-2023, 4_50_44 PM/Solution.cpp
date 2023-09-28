// https://leetcode.com/problems/merge-in-between-linked-lists

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
    ListNode* findEndNode(ListNode *l, int value) {
        if (!l)
            return l;
        while (l->next && value != 1) {
            l = l->next;
            value--;
        }
        return l;
    }

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if (!list1 || !list2)
            return NULL;
        ListNode *t_l1 = findEndNode(list1, a);
        ListNode *nxt = findEndNode(t_l1, b - a + 3);
        t_l1->next = list2;
        ListNode *end_l2 = findEndNode(list2, -1);
        end_l2->next = nxt;

        return list1;
    }
};