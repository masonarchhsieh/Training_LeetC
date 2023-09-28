// https://leetcode.com/problems/thousand-separator

class Solution {
public:
    string thousandSeparator(int n) {
        string res;
        int count_t = 0;

        if (n == 0)
            return "0";

        while (n > 0) {
            if (count_t == 3) {
                res = "." + res;
                count_t = 0;
            }
            res = to_string(n % 10) + res;
            count_t++;
            n /= 10;
        }

        return res;
    }
};