// https://leetcode.com/problems/linked-list-cycle

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
    bool hasCycle(ListNode *head) {
        vector<ListNode*> list;
        bool cycle = false;
        
        while (head != nullptr)
        {
            for (int i=0; i<list.size();i++)
            {
                if (head == list[i])
                {
                    return true;
                }
            }
            
            list.push_back(head);
            
            head = head->next;
        }
        
        
        return false;
    }
};