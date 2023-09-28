// https://leetcode.com/problems/check-if-matrix-is-x-matrix

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[i].size(); j++) {
                if (i == j) {
                    if (grid[i][j] == 0)
                        return false;
                }
                else if (j == grid[i].size() - 1 - i) {
                    if (grid[i][j] == 0)
                        return false;
                }
                else if (grid[i][j] != 0)
                    return false;
            }
        }


        return true;
    }


};