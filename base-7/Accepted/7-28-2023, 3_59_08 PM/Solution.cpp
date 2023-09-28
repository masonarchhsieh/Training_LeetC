// https://leetcode.com/problems/base-7

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        string res;
        bool neg = (num < 0);
        if (num < 0)
            num = abs(num);

        while (num > 0) {
            res = to_string((num % 7)) + res;
            num /= 7;
        }
        if (neg)
            res = "-" + res;
        return res;
    }
};