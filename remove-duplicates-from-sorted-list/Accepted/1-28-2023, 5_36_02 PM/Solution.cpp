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
        if (!head)
            return head;
        vector<ListNode*> list;
        ListNode *itr = head;
        while (itr) {
            list.push_back(itr);
            itr = itr->next;
        }

        vector<ListNode*>::iterator it;
        it = std::unique(list.begin(), list.end(), Pred);
        list.resize(std::distance(list.begin(), it));

        for (int i = 1; i < list.size(); i++)
            list[i-1]->next = list[i];
        list[list.size() -1]->next = nullptr;

        return list[0];
    }
};