// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;
        int t = head->val;
        int cnt = 0;
        head = head->next;
        while (head->next) {
            // local maxima
            if (t < head->val && head->next->val < head->val)
                pos.push_back(cnt);
            // local minima
            else if (t > head->val && head->next->val > head->val)
                pos.push_back(cnt);
            t = head->val;
            head = head->next;
            cnt++;
        }

        if (pos.size() < 2)
            return { -1, -1 };
        int min_d = INT_MAX;
        for (auto i = 1; i < pos.size(); i++)
            min_d = min (min_d, pos[i] - pos[i-1]);

        return {min_d, pos.back() - pos.front()};
    }
};