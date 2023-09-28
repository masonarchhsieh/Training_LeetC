// https://leetcode.com/problems/calculate-digit-sum-of-a-string

class Solution {
public:
    string digitSum(string s, int k) {
        if (s.length() <= k)
            return s;
        
        string res;
        for (auto i = 0; i < s.length(); i += k) {
            int t = (s[i] - '0');
            for (auto j = 1; j < k; j++)
                if (i < s.length() - j)
                    t += (s[i + j] - '0');
            res += to_string(t);
        }

        return digitSum(res, k);
    }
};