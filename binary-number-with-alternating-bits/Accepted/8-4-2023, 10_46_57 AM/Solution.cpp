// https://leetcode.com/problems/binary-number-with-alternating-bits

class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n > 0) {
            if ((n & 0x1) == (((n >> 1) & 0x1)))
                return false;
            n >>= 1;
        }
        return true;
    }
};