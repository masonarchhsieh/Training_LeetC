class Solution {
    const int MOD = 1e9 + 7;
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {1};
        
        for (auto i = 1; i <= n; i++) {
            for (auto j = 0; j <= k; j++) {
                for (auto x = 0; x <= min(j, i - 1); x++) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % MOD;
                }
            }
        }
        
        return dp[n][k];
    }
};