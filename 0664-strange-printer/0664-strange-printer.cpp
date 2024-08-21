class Solution {
public:
    int strangePrinter(string s) {
        int n = size(s);
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (auto i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (auto j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                for (auto k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            
        }

        return dp[0][n-1];
    }
};