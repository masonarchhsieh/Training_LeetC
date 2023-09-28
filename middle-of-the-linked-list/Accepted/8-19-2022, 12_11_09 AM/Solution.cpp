// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> list;
        while (head != NULL)
        {
            list.push_back(head);
            head = head->next;
        }
        
        
        if (list.size() % 2 == 1)
            return list[list.size() / 2];
        
        return list[(list.size() + 1) / 2];
    }
};