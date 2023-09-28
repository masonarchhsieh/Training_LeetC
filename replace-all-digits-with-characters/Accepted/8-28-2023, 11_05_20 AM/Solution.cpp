// https://leetcode.com/problems/replace-all-digits-with-characters

class Solution {
public:
    string replaceDigits(string s) {
        for (size_t i = 1; i < s.length(); i+=2) {
            s[i] = s[i-1] + (s[i] - '0');
        }
        return s;
    }
};