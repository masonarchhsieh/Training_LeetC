class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = size(matrix);
        int columns = size(matrix.front());
        
        for (auto i = 1; i < rows; i++) {
            for (auto j = 0; j < columns; j++) {
                if (j == 0)
                     matrix[i][j] = matrix[i][j] + min(matrix[i-1][j], matrix[i-1][j+1]);
                else if (j == columns - 1)
                     matrix[i][j] = matrix[i][j] + min(matrix[i-1][j-1], matrix[i-1][j]);
                else
                    matrix[i][j] = matrix[i][j] + min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i-1][j+1]));
            }
        }
        
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};