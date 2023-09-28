// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int x = 32;
        uint32_t res = 0x0;

        while (x-- > 0) {
            res <<= 1;
            res = res | (n & 0x1);
            n >>= 1;
        }
        return res;
    }
};