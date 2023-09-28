// https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0;
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid.size(); j++) {
                if (helper(grid, i, j))
                    res++;
            }
        }
        return res;
    }

    bool helper(vector<vector<int>>& grid, int x, int y) {
        vector<int> t1, t2;
        for (auto i = 0; i < grid.size(); i++) {
            t1.push_back(grid[x][i]);
            t2.push_back(grid[i][y]);
        }

        return t1 == t2;
    }
};