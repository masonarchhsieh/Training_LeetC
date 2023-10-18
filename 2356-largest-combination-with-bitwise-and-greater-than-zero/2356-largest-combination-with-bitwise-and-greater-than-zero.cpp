class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        unordered_map<int, int> m;
        int res = 0;
        countBits(m, candidates);
        for (auto i : m)
            res = max(res, i.second);

        return res;
    }

    void countBits(unordered_map<int, int>& m, vector<int>& candidates) {
        for (auto i : candidates) {
            int b_idx = 0;
            while (i > 0) {
                if (i & 0x1) {
                    m[b_idx]++;
                }
                i >>= 1;
                b_idx++;
            }
        }
    }
};