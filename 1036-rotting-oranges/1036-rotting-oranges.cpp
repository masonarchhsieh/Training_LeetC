class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited(size(grid), vector<int>(grid[0].size(), 0));
        for (auto i = 0; i < size(grid); i++)
            for (auto j = 0; j < size(grid[0]); j++)
                if (grid[i][j] == 2)
                    dfs(grid, i, j);

        int res = 2;
        for (auto &i : grid) {
            for (auto &j : i) {
                if (j == 1)
                    return -1;
                res = max(res, j);
            }
        }

        return res - 2;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int depth = 2) {
        // boundary checking
        if (i < 0 || j < 0 || i >= size(grid) || j >= size(grid[0]))
            return;
        if (grid[i][j] == 0 || (1 < grid[i][j] && grid[i][j] < depth))
            return;
        grid[i][j] = depth;
        dfs(grid, i - 1, j, depth + 1);
        dfs(grid, i + 1, j, depth + 1);
        dfs(grid, i, j - 1, depth + 1);
        dfs(grid, i, j + 1, depth + 1);
    }
};