class NumMatrix {
    vector<vector<int>> m;
    vector<vector<int>> m_prefix_sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m.clear();
        m = matrix;

        for (auto i = 0; i < size(m); i++)
            for (auto j = 1; j < size(m[0]); j++)
                m[i][j] += m[i][j - 1];

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;

        for (int i = row1; i <= row2; i++) {
            if (col1 == 0)
                res += m[i][col2];
            else
                res += m[i][col2] - m[i][col1 - 1];
        }

        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */