// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ops = 0;

        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                continue;
            ops++;
            int t = nums[i];
            for (auto &j : nums) {
                j -= t;
            }
        }

        return ops;
    }
};