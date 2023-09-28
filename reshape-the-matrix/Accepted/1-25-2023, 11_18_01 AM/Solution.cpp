// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> res(r, vector<int>(c, 0));
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c)
            return mat;

        for (auto i = 0; i < mat.size(); i++) {
            for (auto j = 0; j < mat[0].size(); j++) {
                int k = i * n + j;
                res[k / c][k % c] = mat[i][j]; 
            }
        }

        return res;
    }
};