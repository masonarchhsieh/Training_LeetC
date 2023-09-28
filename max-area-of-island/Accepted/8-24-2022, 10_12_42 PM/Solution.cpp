// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j] == 1)
                    res = max(res, dfs(grid, i, j));

        return res;
    }
    
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int res = 0;
        
        if (grid[x][y] == 1) {
            grid[x][y] = 0;
            res = 1;
            if (x - 1 >= 0)
                res += dfs(grid, x-1, y);
            if (y - 1 >= 0)
                res += dfs(grid, x, y-1);
            if (x + 1 < grid.size())
                res += dfs(grid, x+1, y);
            if (y + 1 < grid[0].size())
                res += dfs(grid, x, y+1);
        }
        return res;
    }
    
};