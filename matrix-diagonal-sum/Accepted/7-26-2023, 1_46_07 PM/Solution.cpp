// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;

        for (auto i = 0; i < mat.size(); i++)
            res += mat[i][i] + mat[i][mat[0].size() - 1 - i];
        if (mat.size() % 2 == 1)
            res -= mat[mat.size() / 2][mat[0].size() / 2];
        return res;
    }
};