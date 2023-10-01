class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (auto i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - 1 - i]) {
                s[i] = min(s[i], s[s.length() - 1 - i]);
                s[s.length() - 1 - i] = min(s[i], s[s.length() - 1 - i]);
            }
        }
        return s;
    }
};