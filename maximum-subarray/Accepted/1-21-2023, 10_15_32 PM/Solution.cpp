// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[100000] = { 0 };
        dp[0] = nums[0];
        int res = dp[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (res < dp[i])
                res = dp[i];
        }

        return res;
    }
};