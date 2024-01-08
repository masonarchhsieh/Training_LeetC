class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, res = 0;
        for (size_t i = 0; i < size(s); i++)
            ones += (s[i] == '1');
        for (size_t i = 0; i < size(s) - 1; i++) {
            if (s[i] == '0')
                zeros++;
            else
                ones--;
            res = max(res, zeros + ones);
        }

        return res;
    }
};