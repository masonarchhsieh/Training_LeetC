// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (auto i = 1; i < grid[0].size(); i++)
            grid[0][i] += grid[0][i-1];
        for (auto i = 1; i < grid.size(); i++)
            grid[i][0] += grid[i-1][0];

        for (auto i = 1; i < grid.size(); i++) {
            for (auto j = 1; j < grid[0].size(); j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid.back().back();
    }
};