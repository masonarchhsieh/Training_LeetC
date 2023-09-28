// https://leetcode.com/problems/consecutive-characters

class Solution {
public:
    int maxPower(string s) {
        int res = 1, tmp = 1;
        for (auto i = 1; i < s.length(); i++)
            if (s[i] == s[i - 1]) {
                tmp++;
                res = max(res, tmp);
            } else {
                res = max(res, tmp);
                tmp = 1;
            }

        return res;
    }
};