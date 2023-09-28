// https://leetcode.com/problems/reverse-nodes-in-even-length-groups

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
    void reverseList(vector<ListNode*>& v, int start, int end) {
        if (start >= end || end >= v.size())
            return;
        
        int range = (end - start + 1) / 2;
        for (auto i = 0; i < range; i++)
            swap(v[start + i], v[end - i]);
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *itr = head;
        vector<ListNode*> v;
        while (itr) {
            v.push_back(itr);
            itr = itr->next;
        }

        int c = 0;
        for (auto i = 0; i < v.size(); i+=c) {
            c++;
            if (c % 2 == 0) {
                if (i + c >= v.size() && (v.size() - i) % 2 == 0) {
                    reverseList(v, i, v.size() - 1);
                } else if (i + c < v.size()) {
                    reverseList(v, i, i + c - 1);
                }
            }
            else if (v.size() - i  < c && (v.size() - i) % 2 == 0) {
                reverseList(v, i, v.size() - 1);
            }
        }

        for (auto i = 1; i < v.size(); i++)
            v[i-1]->next = v[i];
        v[v.size() - 1]->next = NULL;

        return v[0];
    }
};