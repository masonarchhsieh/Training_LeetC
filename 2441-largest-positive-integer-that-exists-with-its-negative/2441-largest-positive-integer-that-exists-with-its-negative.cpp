class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = -1;

        for (auto &i : nums) {
            if (m[abs(i)] + i == 0) {
                res = max(res, abs(i));
                continue;
            }
            m[abs(i)] = i;
        }

        return res;
    }
};