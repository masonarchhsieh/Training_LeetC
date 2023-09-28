// https://leetcode.com/problems/largest-local-values-in-a-matrix

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal;
        for (auto i = 0; i < n - 2; i++) {
            vector<int> tmp;
            tmp.assign(n - 2, 0);
            maxLocal.push_back(tmp);
        }

        for (auto i = 1; i < n - 1; i++) {
            for (auto j = 1; j < n - 1; j++) {
                maxLocal[i-1][j-1] = findMax(grid, i, j);
            }
        }

        return maxLocal;
    }

    int findMax(vector<vector<int>>& grid, int x, int y) {
        int res = INT_MIN;
        for (auto i = x - 1; i <= x + 1; i++) {
            for (auto j = y - 1; j <= y + 1; j++) {
                res = max(res, grid[i][j]);
            }
        }
        return res;
    } 
};