// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation

class Solution {
    vector<int> primeBit_list = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
public:
    int countPrimeSetBits(int left, int right) {
        if (left > right)
            return 0;
        int primeBits = 0, tmp = left, res = 0;
        while (tmp > 0) {
            if (tmp & 0x1)
                primeBits++;
            tmp >>= 1;
        }
        if (find(primeBit_list.begin(), primeBit_list.end(), primeBits) != primeBit_list.end())
            res = 1;

        return res + countPrimeSetBits(left + 1, right);
    }
};