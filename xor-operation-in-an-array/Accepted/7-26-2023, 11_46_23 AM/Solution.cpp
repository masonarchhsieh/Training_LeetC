// https://leetcode.com/problems/xor-operation-in-an-array

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> tmp;
        for (auto i = start; i < start + 2 * n; i += 2)
            tmp.push_back(i);
        int res = tmp[0];
        for (auto i = 1; i < tmp.size(); i++)
            res ^= tmp[i];

        return res;
    }
};