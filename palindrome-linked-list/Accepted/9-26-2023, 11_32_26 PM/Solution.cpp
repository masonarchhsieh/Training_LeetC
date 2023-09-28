// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> v;
        ListNode *itr = head;
        while (itr) {
            v.push_back(itr);
            itr = itr->next;
        }
        for (auto i = 0; i < v.size() / 2; i++)
            if (v.at(i)->val != v.at(v.size() - 1 - i)->val)
                return false;
        return true;
    }
};