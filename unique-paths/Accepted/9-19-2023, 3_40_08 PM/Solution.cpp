// https://leetcode.com/problems/unique-paths

class Solution {
    int dp[100][100];
public:
    int uniquePaths(int m, int n) {   
        for (auto i = 0, j = 0; j < n; j++)
            dp[i][j] = 1;    
        for (auto j = 0, i = 0; i < m; i++)
            dp[i][j] = 1;
        
        for (auto i = 1; i < m; i++) {
            for (auto j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
    
};