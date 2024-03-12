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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        while (head) {
            if (head->val != 0)
                v.emplace_back(head->val);
            head = head->next;
        }

        int l = 0;
        while (l < v.size()) {
            int acc = v[l];
            int r = l + 1;
            while (acc != 0 && r < v.size()) {
                acc += v[r];
                r++;
            }

            if (acc == 0) {
                v.erase(v.begin() + l, v.begin() + r);
            }
            else
                l++;
        }

        if (v.size() == 0)
            return NULL;
        ListNode *r = new ListNode(v.front());
        ListNode *itr = r;
        for (auto i = 1; i < v.size(); i++) {
            itr->next = new ListNode(v[i]);
            itr = itr->next;
        }
        return r;
    }
};