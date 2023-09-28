// https://leetcode.com/problems/sum-of-digits-of-string-after-convert

class Solution {
public:
    int getLucky(string s, int k) {
        string sum_s;
        int sum = 0;
        if (!isdigit(s[0]))
            for (size_t i = 0; i < s.length(); i++)
                sum_s += to_string(s[i] - 'a' + 1);
        else
            sum_s = s;
        for (size_t i = 0; i < sum_s.length(); i++) {
            sum += (sum_s[i] - '0');
        }
        if (sum >= 10 && k > 1)
            return getLucky(to_string(sum), k - 1);
        return sum;
    }
};