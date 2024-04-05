class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for (auto i = 0; i < s.length(); i++) {
            if (!st.empty() && (st.top() != s[i] && tolower(s[i]) == st.top()))
                st.pop();
            else if (!st.empty() && (st.top() != s[i] && s[i] == tolower(st.top())))
                st.pop();
            else
                st.push(s[i]);
        }
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};