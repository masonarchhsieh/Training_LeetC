// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)
            return 1;

        long itr = x / 2;
        for (itr; itr * itr >= x; itr /= 2)
            if (itr * itr == x)
                return itr;
        for (itr; itr >= 0 && itr * itr <= x; itr++)
            if (itr * itr == x)
                return itr;

        return itr - 1;
    }
};