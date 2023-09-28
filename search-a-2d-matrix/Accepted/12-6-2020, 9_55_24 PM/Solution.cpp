// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        
        int n = matrix[0].size();
        if (n == 0)
            return false;
        
        for (int i=0; i<m; i++) {
            if (matrix[i][n-1] >= target) {
                for (int j=0; j<n; j++) {
                    if (matrix[i][j] == target)
                        return true;
                }
                return false;
            }
            
        }
        
        return false;
    }
};