// https://leetcode.com/problems/next-greater-node-in-linked-list

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        
        while (head != NULL) {
            ListNode* itr = head;
            int v = 0;
            for(;itr;itr=itr->next) {
                if (head->val < itr->val) {
                    v = itr->val;
                    break;
                }                
            }
            res.push_back(v);
            
            head = head->next;
        }       
        
        return res;
    }
};