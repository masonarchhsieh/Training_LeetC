// https://leetcode.com/problems/binary-gap

class Solution {
public:
    int binaryGap(int n) {
        int count = 0, res = 0;
        vector<int> tmp;

        while (n > 0) {
            if (n & 0x1)
                tmp.push_back(count);
            n >>= 1;
            count++;
        }
        for (auto i = 1; i < tmp.size(); i++) {
            res = max(res, tmp[i] - tmp[i-1]);
        }


        return res;
    }
};