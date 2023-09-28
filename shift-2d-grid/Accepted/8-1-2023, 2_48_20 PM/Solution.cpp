// https://leetcode.com/problems/shift-2d-grid

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (k == 0)
            return grid;

        int tmp = grid[0][0], tmp2;
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[0].size(); j++) {
                tmp = tmp2;
                tmp2 = grid[i][j];
                if (j > 0)
                    grid[i][j] = tmp;
                if (j == 0 && i != 0)
                    grid[i][j] = tmp;
            }
        }
        grid[0][0] = tmp2;
        return shiftGrid(grid, --k);
    }
};