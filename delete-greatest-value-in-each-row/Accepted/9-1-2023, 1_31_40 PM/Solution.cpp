// https://leetcode.com/problems/delete-greatest-value-in-each-row

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        vector<int> t(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++)
            sort(grid[i].begin(), grid[i].end());
        for (auto j = 0; j < grid[0].size(); j++) {
            for (auto i = 0; i < grid.size(); i++) {
                t[j] = max(t[j], grid[i][j]);
            }
        }


        return accumulate(t.begin(), t.end(), 0);
    }
};