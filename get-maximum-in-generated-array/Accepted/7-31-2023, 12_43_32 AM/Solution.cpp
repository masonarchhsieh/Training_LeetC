// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    int getMaximumGenerated(int n) {
        int dp[n + 1];
        if (n <= 1)
            return n;
        
        dp[0] = 0, dp[1] = 1;
        int res = dp[0];
        for (auto i = 1; i <= n/2; i++) {
            dp[2*i] = dp[i];
            res = max(res, dp[2*i]);
            if (2*i + 1 <= n) {
                dp[2*i+1] = dp[i] + dp[i+1];
                res = max(res, dp[2*i+1]);
            }
        } 
        return res;
    }
};