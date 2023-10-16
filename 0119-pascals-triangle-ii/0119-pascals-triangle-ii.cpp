class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascalTriangle;
        pascalTriangle.push_back({ 1 });
        pascalTriangle.push_back({ 1, 1 });
        for (auto i = 2; i < rowIndex + 1; i++) {
            vector<int> v { 1 };
            for (auto j = 1; j < pascalTriangle[i-1].size(); j++) {
                v.push_back(pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j]);
            }
            v.push_back(1);
            pascalTriangle.push_back(v);            
        }
        return pascalTriangle[rowIndex];
    }
};