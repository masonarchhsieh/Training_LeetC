// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[100000] = {0};
        dp[0] = nums[0];
        int res = dp[0];
        
        for (int i=1; i<nums.size(); i++) {
            if (dp[i-1] < 0) {
                dp[i] = max(dp[i-1]  + nums[i], nums[i]);
                if (res < dp[i])
                    res = dp[i];
            }
            else {
                dp[i] = max(nums[i], dp[i-1] + nums[i]);
                if (res < dp[i])
                    res = dp[i];
            }
        }
        
        
        return res;
    }
};