// https://leetcode.com/problems/minimum-bit-flips-to-convert-number

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start ^ goal;
        int cnt = 0;
        while (res > 0) {
            cnt += (res & 0x1);
            res >>= 1;
        }
        return cnt;
    }
};