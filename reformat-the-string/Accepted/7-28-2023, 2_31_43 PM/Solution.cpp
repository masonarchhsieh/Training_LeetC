// https://leetcode.com/problems/reformat-the-string

class Solution {
public:
    string reformat(string s) {
        vector<char> s_v, d_v;

        for (auto i = 0; i < s.length(); i++) {
            if (isalpha(s[i]))
                s_v.push_back(s[i]);
            else if (isdigit(s[i]))
                d_v.push_back(s[i]);
            else
                return "";
        }

        if (abs((int)(s_v.size() - d_v.size())) > 1)
            return "";

        bool is_alpha_first = s_v.size() > d_v.size();
        int i = 0, itr_s = 0, itr_d = 0;
        while (i < s.length()) {
            if (is_alpha_first)
                s[i++] = s_v[itr_s++];
            else
                s[i++] = d_v[itr_d++];
            is_alpha_first = !is_alpha_first;
        }
        return s;
    }
};