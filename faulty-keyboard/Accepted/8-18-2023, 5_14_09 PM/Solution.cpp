// https://leetcode.com/problems/faulty-keyboard

class Solution {
public:
    string finalString(string s) {
        string res;
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == 'i')
                reverse(res.begin(), res.end());
            else
                res += s[i];
        }

        return res;
    }
};