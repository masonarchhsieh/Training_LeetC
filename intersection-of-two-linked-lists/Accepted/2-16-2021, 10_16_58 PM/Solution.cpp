// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> v1, v2;
        
        while (headA) {
            v1.push(headA);
            headA = headA->next;
        }
        
        while (headB) {
            v2.push(headB);
            headB = headB->next;
        }
        
        ListNode* res = NULL;
        while (v1.size() > 0 && v2.size() > 0 && v1.top() == v2.top()) {
            res = v1.top();
            v1.pop();
            v2.pop();
        }
        if (!res)
            return NULL;
        
        return res;
    }
};