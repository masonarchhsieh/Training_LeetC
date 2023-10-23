class Solution {
public:
    bool isPowerOfFour(int n) {
        uint64_t mask = 0x55555555;
        if (n > 0 && (n & (n - 1)) == 0 && (n & mask) == n)
            return true;
        return false;
    }
};