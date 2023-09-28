// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint64_t n) {
        return bitset<32>(n).count();
    }
};