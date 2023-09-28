// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters

class Solution {
public:
    string modifyString(string s) {
        for (auto i = 0; i < s.length(); i++) {
            if (s[i] == '?') {
                char c;
                if (i > 0)
                    c = s[i - 1] + 1;
                if (!islower(c))
                    c = 'a';
                if (i < s.length() - 1)
                    if (c == s[i + 1])
                        c = s[i + 1] + 1;
                if (!islower(c))
                    c = 'a';
                s[i] = c;
            }
        }
        return s;
    }
};