// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *evenNode = head;
        ListNode *oddHead = head->next;
        ListNode *oddNode = head->next;
        ListNode *itr = head->next->next;
        int cnt = 2;
        while (itr) {
            if (cnt % 2 == 0) {
                evenNode->next = itr;
                evenNode = evenNode->next;
            }
            else {
                oddNode->next = itr;
                oddNode = oddNode->next;
            }
            itr = itr->next;
            evenNode->next = NULL;
            oddNode->next = NULL;
            cnt++;
        }
        evenNode->next = oddHead;
        return head;
    }
};