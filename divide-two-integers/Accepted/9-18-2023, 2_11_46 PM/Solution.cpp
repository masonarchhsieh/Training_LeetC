// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return 0;
        if (dividend == INT_MIN)
            return (divisor == -1)? INT_MAX : dividend / divisor;

        return dividend / divisor;
    }
};