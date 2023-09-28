// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getLength(head);
        if (!head)
            return head;
        if (len == 1 || k == 0 || (k % len) == 0)
            return head;

        ListNode *_itr = head, *prev = head;
        for (auto i = 0; i < len - (k % len); i++) {
            prev = _itr;
            _itr = _itr->next;
        }
        cout << _itr->val << endl;
        // link tail to prev
        prev->next = NULL;
        prev = _itr;
        while (_itr->next) {
            _itr = _itr->next;
        }
        _itr->next = head;
        head = prev;


        return head;
    }

    int getLength(ListNode* head) {
        int n = 0;

        while (head) {
            head = head->next;
            n++;
        }

        return n;
    }
};