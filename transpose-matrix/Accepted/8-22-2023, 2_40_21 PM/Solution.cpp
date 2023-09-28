// https://leetcode.com/problems/transpose-matrix

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<int> tmp(matrix.size(), 0);
        vector<vector<int>> res(matrix[0].size(), tmp);

        for (auto i = 0; i < matrix.size(); i++) {
            for (auto j = 0; j < matrix[i].size(); j++) {
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }
};