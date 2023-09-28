// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        long temp = ((long)dividend/(long)divisor);
        
        if (temp >= INT_MAX)
            temp = INT_MAX;
        else if (temp <= INT_MIN)
            temp = INT_MIN;
        
        return (int) temp;
    }
};