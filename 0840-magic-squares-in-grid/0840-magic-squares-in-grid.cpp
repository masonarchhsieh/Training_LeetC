class Solution {
    bool isMagicSquare(int i, int j, vector<vector<int>>& grid) {
        vector<int> cnt(10, 0);

        // grid[][] must be 1 - 9
        for (auto x = 0; x < 3; x++) {
            for (auto y = 0; y < 3; y++) {
                int num = grid[i + x][j + y];
                if (num < 1 || num > 9 || cnt[num] > 0)
                    return false;
                cnt[num]++;
            }
        }
        int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        for (auto x = 0; x < 3; x++) {
            if (sum != (grid[i + x][j] + grid[i + x][j + 1] + grid[i + x][j + 2]))
                return false;
            if (sum != (grid[i][j + x] + grid[i + 1][j + x] + grid[i + 2][j + x]))
                return false;
        }
        if (sum != (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2])) 
            return false;
        if (sum != (grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2])) 
            return false;
        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;

        int m = size(grid), n = size(grid.front());
        if (m < 3 || n < 3)
            return cnt;

        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                cnt += (int) (isMagicSquare(i, j, grid));
            }
        }
        return cnt;
    }
};