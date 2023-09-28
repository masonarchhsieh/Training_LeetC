// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        vector<ListNode*> list;
        while (head != NULL) {
            if (head->val != val)
                list.push_back(head);
            head = head->next;
        }
        
        if (list.size() == 0)
            return NULL;
        
        for (int i=0; i<list.size(); i++)
        {
            if (i == 0)
                list[i]->next = NULL;
            else
                list[i-1]->next = list[i];
        }
        list[list.size() - 1]->next = NULL;
        
        return list[0];
    }
};