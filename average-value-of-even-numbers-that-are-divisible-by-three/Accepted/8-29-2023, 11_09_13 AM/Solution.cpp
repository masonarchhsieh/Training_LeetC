// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (auto i : nums) {
            if (i % 2 == 0 && i % 3 == 0) {
                res += i;
                cnt++;
            }
        }
        if (cnt > 0)
            res /= cnt;

        return res;
    }
};