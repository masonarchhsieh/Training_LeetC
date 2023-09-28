// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        size_t i = 0;
        int idx = 0;
        while (i < s.length() && idx < words.size()) {
            if (s.substr(i, s.length() - i).find(words[idx]) == 0) {
                i += words[idx++].length();
                continue;
            }
            return false;
        }
        return i == s.length();
    }
};