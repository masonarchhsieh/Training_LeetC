// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp = s + s;
        if (tmp.substr(1, tmp.length() - 2).find(s) == std::string::npos)
            return false;

        return true;
    }
};