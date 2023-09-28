// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = 0;
        int count = 32;
        while (count-- > 0)
        {
            if ((0x001 & n) == 0x001)
                x++;            
            n = n >>1;
        }
        return x;
    }
};