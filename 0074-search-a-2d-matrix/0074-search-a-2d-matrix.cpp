class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = 0;
        
        if (target < matrix[0][0])
            return false;

        for (auto i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] > target) {
                row = i - 1;
                break;
            }
            row = i;
        }
        for (auto i = 0; i < matrix[row].size(); i++) {
            if (matrix[row][i] == target)
                return true;
        }
       
        return false;
    }
};