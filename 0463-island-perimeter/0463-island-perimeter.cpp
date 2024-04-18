class Solution {
    int count(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 0)
            return 0;
        int cnt = 0;
        if (i == 0)
            cnt++;
        else
            cnt += (grid[i-1][j] == 0);
        if (i == grid.size() - 1)
            cnt++;
        else
            cnt += (grid[i+1][j] == 0);
        if (j == 0)
            cnt++;
        else
            cnt += (grid[i][j-1] == 0);
        if (j == grid[0].size() - 1)
            cnt++;
        else
            cnt += (grid[i][j+1] == 0);
        return cnt;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[i].size(); j++) {
                perimeter += count(grid, i, j);
            }
        }


        return perimeter;
    }
};