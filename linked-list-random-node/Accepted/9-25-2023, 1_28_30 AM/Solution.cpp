// https://leetcode.com/problems/linked-list-random-node

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
    vector<int> v;
public:
    Solution(ListNode* head) {
        v.clear();
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return v.at(rand() % v.size());
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */