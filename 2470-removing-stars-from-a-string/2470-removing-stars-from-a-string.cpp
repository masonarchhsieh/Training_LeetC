class Solution {
public:
    string removeStars(string s) {
        string res;
        stack<char> st;

        for (auto c : s) {
            if (c == '*') {
                if (!st.empty())
                    st.pop();
                continue;
            }
            st.push(c);
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};