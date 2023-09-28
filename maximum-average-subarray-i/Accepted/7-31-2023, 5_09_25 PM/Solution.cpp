// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double dp = .0f, res = .0f;
        for (auto i = 0; i < k; i++)
            dp += nums[i];
        res = dp;
        for (auto i = 1; i <= nums.size() - k; i++) {
            dp = dp - nums[i-1] + nums[i+k-1];
            res = max(res, dp);
        }

        return res / k;
    }
};