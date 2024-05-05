/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node->next) {
            node = NULL;
            return;
        }

        ListNode *itr = node, *nxt = node->next;
        while (itr) {
            while (nxt && nxt->val == node->val) {
                nxt = nxt->next;
            }
            if (!nxt) {
                itr->next = NULL;
                break;
            }
            itr->val = nxt->val;
            nxt = nxt->next;
            if (!nxt) {
                break;
            }
            itr = itr->next;
        }
        itr->next = NULL;
    }
};