// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int x = 32;
        uint32_t res = 0x0000;
        while (x-- > 0)
        {
            res = (0x00000001 & n) + (res << 1);
            n = n >> 1;
        }
        
        return res;
    }
};