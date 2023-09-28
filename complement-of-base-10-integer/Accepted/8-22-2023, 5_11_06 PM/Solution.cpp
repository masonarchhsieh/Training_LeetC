// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        int res = 0;
        vector<int> tmp;
        while (n > 0) {
            tmp.push_back(n % 2);
            n >>= 1;
        }
        reverse(tmp.begin(), tmp.end());
        for (auto i : tmp)
            res = (res <<= 1) + (i != 1);

        return res;
    }
};