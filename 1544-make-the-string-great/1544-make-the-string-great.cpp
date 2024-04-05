class Solution {
public:
    string makeGood(string s) {
        string res = "";
        stack<char> st, good_st;
        for (size_t i = 0; i < s.length(); i++)
            st.push(s[i]);
        
        while (!st.empty()) {
            string tmp(1, st.top());
            
            if (!good_st.empty() && good_st.top() != st.top() && tolower(good_st.top()) == tolower(st.top())) {
                good_st.pop();
            }
            else
                good_st.push(st.top());
            st.pop();
        }

        while (!good_st.empty()) {
            string tmp(1, good_st.top());
            res += tmp;
            good_st.pop();
        }

        return res;
    }
};