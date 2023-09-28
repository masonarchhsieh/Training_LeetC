// https://leetcode.com/problems/maximum-score-after-splitting-a-string

class Solution {
public:
    int maxScore(string s) {
        return helper(s, 1);
    }

    int helper(string s, int itr) {
        if (itr > s.length() - 1)
            return 0;
        int tmp = 0;
        for (auto i = 0; i < itr; i++)
            if (s[i] == '0')
                tmp++;
        for (auto i = itr; i < s.length(); i++)
            if (s[i] == '1')
                tmp++;

        return max(tmp, helper(s, itr + 1));
    }
};