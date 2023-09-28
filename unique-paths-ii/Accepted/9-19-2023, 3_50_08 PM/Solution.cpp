// https://leetcode.com/problems/unique-paths-ii

class Solution {
    int dp[100][100] = {0};
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        
        for (auto j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1)
                break;
            dp[0][j] = 1;
        }
        for (auto i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) 
                break;
            dp[i][0] = 1;
        }

        for (auto i = 1; i < m; i++) {
            for (auto j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};