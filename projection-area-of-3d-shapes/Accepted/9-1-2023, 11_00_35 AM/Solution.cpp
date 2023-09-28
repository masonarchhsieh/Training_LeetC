// https://leetcode.com/problems/projection-area-of-3d-shapes

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        // from z
        int z = 0;
        for (auto i : grid)
            for (auto j : i)
                if (j != 0)
                    z++;
        // from x
        int x = 0;
        for (auto i : grid) {
            int max_x = 0;
            for (auto j : i)
                max_x = max(max_x, j);
            x += max_x;
        }
        // from y
        int y = 0;
        vector<int> y_l(grid.size(), 0);
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[0].size(); j++) {
                y_l[j] = max(y_l[j], grid[i][j]);
            }
        }
        y = accumulate(y_l.begin(), y_l.end(), 0);
        return x + y + z;
    }
};