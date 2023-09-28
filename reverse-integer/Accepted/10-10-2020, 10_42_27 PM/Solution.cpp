// https://leetcode.com/problems/reverse-integer

#include <math.h>

class Solution {
public:
    int reverse(int x) {
        long int res = 0;
        int sign = 1;
        if (x < 0)
        {
            sign = -1;
            x = abs(x);
        }
        while (x > 0)
        {
            res = res * 10 + x % 10;
            x = x / 10;
        }
        
        if (res < INT_MAX && res > INT_MIN)
            return (int) sign * res;
        else
            return 0;
                
    }
};