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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *itr = list1;
        ListNode *prev;
        ListNode *nxt;
        int cnt = 0;
        bool found_a = false;

        while (itr) {
            if (cnt == a)
                found_a = true;
            if (cnt == b) {
                nxt = itr->next;
                break;
            }

            if (!found_a)
                prev = itr;
            itr = itr->next;
            cnt++;
        }

        prev->next = list2;

        while (list2->next != NULL) {
            list2 = list2->next;
        }
        list2->next = nxt;

        return list1;
    }
};