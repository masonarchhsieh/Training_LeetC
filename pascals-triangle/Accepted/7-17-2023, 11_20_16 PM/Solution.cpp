// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (auto i = 0; i < numRows; i++) {
            vector<int> layer;
            for (auto j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    layer.push_back(1);
                else
                    layer.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            res.push_back(layer);
        }
       
        return res;
    }
};