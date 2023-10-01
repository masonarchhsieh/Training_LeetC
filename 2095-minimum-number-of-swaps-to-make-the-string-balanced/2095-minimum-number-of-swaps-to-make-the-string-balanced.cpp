class Solution {
public:
    int minSwaps(string s) {
        size_t i = 0, r_i = s.length() - 1;
        int len = s.length();
        int cnt = 0;
        stack<char> st;

        while (i < len) {
            if (s[i] == '[')
                st.push(s[i]);
            else if (s[i] == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    for (auto j = r_i; j > i; j--) {
                        if (s[j] == '[') {
                            cnt++;
                            r_i = j - 1;
                            swap(s[i], s[j]);
                            st.push(s[i]);
                            break;
                        }
                    }
                }
            }

            i++;
        }

        return cnt;
    }
};