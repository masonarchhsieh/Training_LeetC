// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first rotation
        // with respect to main diagonal
        for (auto i = 0; i < matrix.size(); i++) {
            for (auto j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // second rotation
        // with respect to the middle column
        for (auto i = 0; i < matrix.size(); i++) {
            for (auto j = 0; j < matrix.size() / 2; j++) {
                swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
            }
        }
    }
};