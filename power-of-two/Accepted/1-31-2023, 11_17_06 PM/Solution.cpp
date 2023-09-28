// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n > 0) 
            return (n & -n) == n;
        return false;
    }
};