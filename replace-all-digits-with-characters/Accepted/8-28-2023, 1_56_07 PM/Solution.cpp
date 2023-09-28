// https://leetcode.com/problems/replace-all-digits-with-characters

class Solution {
public:
    string replaceDigits(string s) {
        string res;
        for (size_t i = 0; i < s.length(); i+=2) {
            res.push_back(s[i]);
            if (i + 1 < s.length()) 
                res.push_back(shift(s[i], s[i + 1] - '0')); 
        }
        return res;
    }

    char shift(char s, int n) {
        return s + n;
    }
};