// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        stack<char> st;
        
        for (size_t i = 0; i < s.length(); i++) {
            if (!st.empty() && st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
        }

        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};