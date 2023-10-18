class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int res = 0, n = size(grid), m = size(grid[0]);
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        pair<int, int> start;
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    start = {i, j};
                    backtrack(grid, visited, i, j, n, m, res);
                }
            }

        return res;
    }

    void backtrack(vector<vector<int>>& grid, vector<vector<bool>> visited, int x, int y, int n, int m, int& res) {
        if (x < 0 || x >= n)
            return;
        if (y < 0 || y >= m)
            return;
        if (visited[x][y])
            return;
        if (grid[x][y] == -1)
            return;
        
        visited[x][y] = true;
        if (grid[x][y] == 2) {
            for (auto i = 0; i < n; i++) {
                for (auto j = 0; j < m; j++) {
                    if (grid[i][j] != 0)
                        continue;
                    if (!visited[i][j])
                        return;
                }
            }
            res++;
            return;
        }
        backtrack(grid, visited, x + 1, y, n, m, res);
        backtrack(grid, visited, x - 1, y, n, m, res);
        backtrack(grid, visited, x, y + 1, n, m, res);
        backtrack(grid, visited, x, y - 1, n, m, res);
        visited[x][y] = false;
    }

};