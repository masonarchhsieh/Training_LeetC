// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        long dp[m+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        for(int j=1; j<=n; j++) {
            long pre = 1;
            for (int i=1; i<=m; i++) {
                long temp = dp[i];
                dp[i] = dp[i] + (t[i-1] == s[j-1] ? pre : 0);
                pre = temp;
            }
        }
        
        
        return dp[m];
    }
};