class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal_triangle;
        for (auto i = 0; i <= rowIndex; i++) {
            vector<int> tmp(i + 1, 1);
            for (auto j = 1; j < i; j++)
                tmp[j] = pascal_triangle[i-1][j] + pascal_triangle[i-1][j-1];
            pascal_triangle.push_back(tmp);
        }

        return pascal_triangle[rowIndex];
    }
};