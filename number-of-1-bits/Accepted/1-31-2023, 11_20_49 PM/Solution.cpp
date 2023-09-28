// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint64_t n) {
        int weights = 0;
        for (auto i = 0; i < 32; i++)
        {
            if (n & 1)
                weights++;
            n >>= 1;
        }
        return weights;
    }
};