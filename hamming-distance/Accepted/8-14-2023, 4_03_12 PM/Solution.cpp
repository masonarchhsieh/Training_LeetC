// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        int tmp = x ^ y;
        while (tmp > 0) {
            if (tmp & 0x1)
                cnt++;
            tmp >>= 1;
        }
        return cnt;
    }
};