// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        int dp[46] = { 0 };
        dp[1] = 1;
        dp[2] = 2;

        for (auto i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n];
    }
};