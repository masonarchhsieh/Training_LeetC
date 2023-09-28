// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
    int pairSum(ListNode* head) {
        if (!head)
            return 0;
        vector<int> v;

        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        int res = 0;

        for (auto i = 0; i < v.size() / 2; i++) {
            res = max(res, v.at(i) + v.at(v.size() - 1 - i));
        }


        return res;
    }
};