// https://leetcode.com/problems/lucky-numbers-in-a-matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        for (auto i = 0; i < matrix.size(); i++) {
            auto min_idx = 0;
            for (auto j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] < matrix[i][min_idx]) {
                    min_idx = j;
                }
            }

            bool update = true;
            for (auto k = 0; k < matrix.size(); k++) {
                if (matrix[k][min_idx] > matrix[i][min_idx]) {
                    update = false;
                    break;
                }
            }
            if (update)
                res.push_back(matrix[i][min_idx]);
        }

        return res;
    }
};