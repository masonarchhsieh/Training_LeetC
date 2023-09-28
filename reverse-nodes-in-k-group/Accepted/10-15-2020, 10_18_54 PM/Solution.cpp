// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* itr = head;
        bool first = true;
        bool stop = false;
        ListNode* prev;
        while (itr != nullptr) {
            vector<ListNode*> temp;
            for (int i=0; i<k; i++) {
                if (itr == nullptr) {
                    return head;
                }
                temp.push_back(itr);
                itr = itr->next;
            }

            swapNode(temp);
            if (first) {
                head = temp[temp.size()-1];
                first = false;
            }
            else {
                prev->next = temp[temp.size()-1];
            }    
            prev = temp[0];
        }
        
        
        return head;
    }
    
    void swapNode(vector<ListNode*>& list) {
        ListNode* nextNode = list[list.size()-1]->next;
        for (int i=list.size()-1; i>0; i--) {
            list[i]->next = list[i-1];
        }
        list[0]->next = nextNode;
    }
};