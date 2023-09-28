// https://leetcode.com/problems/remove-nodes-from-linked-list

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
    ListNode* removeNodes(ListNode* head) {
        ListNode *itr = head;
        stack<ListNode*> st;
        while (itr) {
            st.push(itr);
            itr = itr->next;
        }

        int m = st.top()->val;
        itr = st.top();
        st.pop();

        while (!st.empty()) {
            if (st.top()->val >= m) {
                st.top()->next = itr;
                itr = st.top();
                m = st.top()->val;
            }
            st.pop();
        }

        return itr;
    }
};