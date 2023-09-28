// https://leetcode.com/problems/find-the-width-of-columns-of-a-grid

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size(), 0);

        for (auto i = 0; i < grid[0].size(); i++) {
            for (auto j = 0; j < grid.size(); j++) {
                string s = to_string(grid[j][i]);
                res[i] = max(res[i], (int) s.length());
            }
        }

        return res;
    }
};