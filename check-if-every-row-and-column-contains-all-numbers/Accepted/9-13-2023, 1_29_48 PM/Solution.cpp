// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // check row
        // check column
        for (auto i = 0; i < n; i++) {
            unordered_set<int> t_col;
            unordered_set<int> t_row;
            for (auto j = 0; j < n; j++) {
                t_col.insert(matrix[j][i]);
                t_row.insert(matrix[i][j]);
            }
            if (t_col.size() != n || t_row.size() != n)
                return false;
        }


        return true;
    }
};