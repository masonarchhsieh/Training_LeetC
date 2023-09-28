// https://leetcode.com/problems/row-with-maximum-ones

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> res(2, 0);
        
        for (auto i = 0; i < mat.size(); i++) {
            int t = count(mat[i].begin(), mat[i].end(), 1);
            if (res.back() < t)
                res = { i, t };
        }

        return res;
    }
};