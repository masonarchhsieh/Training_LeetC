// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters

class Solution {
public:
    int countGoodSubstrings(string s) {
        int cnt = 0;
        for (auto i = 2; i < s.length(); i++) {
            if (distinctChars(s[i-2], s[i-1], s[i]))
                cnt++;
        }
        return cnt;
    }

    bool distinctChars(char a, char b, char c) {
        return (a != b) && (b != c) && (c != a);
    }
};