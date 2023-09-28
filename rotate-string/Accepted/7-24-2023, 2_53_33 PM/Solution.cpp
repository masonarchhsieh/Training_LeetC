// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        for (int i = 0; i < s.length(); i++) {
            string tmp = s.substr(i, s.length() - i) + s.substr(0, i);
            if (tmp == goal)
                return true;
        }

        return false;
    }
};