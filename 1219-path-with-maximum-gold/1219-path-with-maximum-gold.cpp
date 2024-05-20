class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        vector<vector<bool>>visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    helper(grid, visited, 0, res, i, j);
                }
            }
        }
        return res;
    }

    void helper(vector<vector<int>>& grid, vector<vector<bool>> &visited, int sum, int &res, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || visited[x][y] || grid[x][y] == 0) {
            res = max(res, sum);
            return;
        }
        visited[x][y] = true;
        sum += grid[x][y];
        helper(grid, visited, sum, res, x - 1, y);
        helper(grid, visited, sum, res, x + 1, y);
        helper(grid, visited, sum, res, x, y - 1);
        helper(grid, visited, sum, res, x, y + 1);
        visited[x][y] = false;
    }
};