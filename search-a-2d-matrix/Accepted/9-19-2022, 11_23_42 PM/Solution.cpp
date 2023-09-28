// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = 0;
        
        if (target < matrix[0][0])
            return false;
        
        for (int i=0; i<m; i++)
            if (matrix[i][0] > target) {
                row = i - 1;
                break;
            }
            else
                row = i;
        
        for (int i=0; i<n; i++)
            if (matrix[row][i] == target)
                return true;
        
        
        return false;
    }
};