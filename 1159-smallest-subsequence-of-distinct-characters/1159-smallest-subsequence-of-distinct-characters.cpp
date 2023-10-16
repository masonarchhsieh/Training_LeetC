class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> inStack(std::size(s), false);
        vector<int> counts(26, 0);
        stack<char> st;

        for (const char c : s)
            counts[c - 'a']++;
        
        for (const char c : s) {
            counts[c - 'a']--;

            if (inStack[c - 'a'])
                continue;
            while (!st.empty() && c < st.top() && counts[st.top() - 'a'] > 0) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            inStack[c - 'a'] = true;
        }

        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};