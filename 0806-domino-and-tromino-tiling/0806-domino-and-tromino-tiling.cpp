class Solution {
    const int MODULE = 1e9 + 7;
public:
    int numTilings(int n) {
        vector<int>dp(n + 1, -1);
        return helper(n, dp);
    }

    int helper(int n, vector<int>& dp) {
        if (n <= 0)
            return 0;
        else if (n == 1)
            return dp[n] = 1;
        else if (n == 2)
            return dp[n] = 2;
        else if (n == 3)
            return dp[n] = 5;
        if (dp[n] != -1)
            return dp[n];
        
        long long res = 2 * 1LL * helper(n - 1, dp) + helper(n - 3, dp);
        return dp[n] = (int) (res % MODULE);
    }
};