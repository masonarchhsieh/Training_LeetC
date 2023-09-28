// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode *nxt_link = NULL;
    bool need_swap = false;
    
public:
    ListNode* findNode(ListNode *head, int pos) {
        if (!head)
            return head;
        int cnt = 0;
        while (head && cnt < pos - 1) {
            head = head->next;
            cnt++;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL)
            return head;
        
        if (left >= right)
            return head;
        ListNode *left_node = findNode(head, left);
        ListNode *right_node = findNode(head, right);

        if (head == left_node) {
            head = reverseList(left_node, right_node);
        } else {
            for (ListNode *itr = head; itr != left_node && itr->next; itr = itr->next) {
                if (itr->next == left_node) {
                    itr->next = reverseList(left_node, right_node);
                    break;
                }
            }
        }
        return head;
    }

    ListNode* reverseList(ListNode *head, ListNode *end) {
        ListNode *prev = NULL;
        ListNode* itr = head;
        while (prev != end) {
            ListNode *nxt = itr->next;
            itr->next = prev;
            prev = itr;
            itr = nxt;
        }
        
        head->next = itr;

        return end;
    }
};