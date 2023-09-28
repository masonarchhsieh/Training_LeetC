// https://leetcode.com/problems/largest-substring-between-two-equal-characters

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1, idx = 0;
        int len = s.length();

        while (idx < len) {
            for (auto i = len - 1; i > idx; i--) {
                if (s[i] == s[idx]) {
                    res = max(i - idx - 1, res);
                    break;
                }
            }
            idx++;
        }

        return res;
    }
};