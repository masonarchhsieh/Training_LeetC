// https://leetcode.com/problems/percentage-of-letter-in-string

class Solution {
public:
    int percentageLetter(string s, char letter) {
        return count(s.begin(), s.end(), letter) * 100 / s.length();
    }
};