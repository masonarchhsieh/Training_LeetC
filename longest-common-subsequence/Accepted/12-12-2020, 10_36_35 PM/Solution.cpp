// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        long dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
            
        for (int j=1; j<=n; j++) {
            for (int i=1; i<=m; i++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
};