class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0; 
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        if (i + 1 < grid.size() && grid[i + 1][j] == '1')
            dfs(grid, i + 1, j);
        if (j + 1 < grid[i].size() && grid[i][j + 1] == '1')
            dfs(grid, i, j + 1);
        if (i - 1 >= 0 && grid[i - 1][j] == '1')
            dfs(grid, i - 1, j);
        if (j - 1>= 0 && grid[i][j - 1] == '1')
            dfs(grid, i, j - 1);
    }
};