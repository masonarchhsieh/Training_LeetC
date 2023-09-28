// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution {
public:
    int maxDepth(string s) {
        if (s == "")
            return 0;

        stack<char> st;
        int itr = 0;
        while (itr < s.length()) {
            if (s[itr] == '(' || s[itr] == ')')
                st.push(s[itr]);
            itr++;
        }
        int depth = 0, max_res = 0;
        while (!st.empty()) {
            if (st.top() == ')')
                depth++;
            else
                depth--;
            st.pop();
            max_res = max(max_res, depth);
        }
        return max_res;
    }
};