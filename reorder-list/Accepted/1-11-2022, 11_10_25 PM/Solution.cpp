// https://leetcode.com/problems/reorder-list

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
    void reorderList(ListNode* head) {
        ListNode *itr = head;
        vector<ListNode*> tmpList;
        
        while (itr != NULL)
        {
            tmpList.push_back(itr);
            itr = itr->next;
        }
        
        if (tmpList.size() <= 2)
            return;
        
        for (int i = 0; i < tmpList.size() / 2; i++)
        {
            tmpList.at(i)->next = tmpList.at(tmpList.size() - 1 - i);
            if (i < tmpList.size() / 2 - 1)
                tmpList.at(tmpList.size() - 1 - i)->next = tmpList.at(i + 1);
        }
        if (tmpList.size() % 2 == 0)
            tmpList.at(tmpList.size() / 2)->next = NULL;
        else
        {
            tmpList.at(tmpList.size() / 2 + 1)->next =  tmpList.at(tmpList.size() / 2);
            tmpList.at(tmpList.size() / 2)->next = NULL;
        }        
    }
};