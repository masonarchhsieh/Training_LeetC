class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int dp2 = 0, dp3 = 0, dp5 = 0;
        
        for (auto i = 1; i < n; i++) {
            dp[i] = min(dp[dp2] * 2, min(dp[dp3] * 3, dp[dp5] * 5));
            if (dp[i] == dp[dp2] * 2)
                dp2++;
            if (dp[i] == dp[dp3] * 3)
                dp3++;
            if (dp[i] == dp[dp5] * 5)
                dp5++;
        }
        return dp.back();
    }
};