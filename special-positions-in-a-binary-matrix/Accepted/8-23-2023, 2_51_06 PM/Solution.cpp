// https://leetcode.com/problems/special-positions-in-a-binary-matrix

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        for (auto i = 0; i < mat.size(); i++)
            for (auto j = 0; j < mat[i].size(); j++)
                if (mat[i][j] == 1) 
                    if (isSpecial(mat, i, j))
                        cnt++;

        return cnt;
    }

    bool isSpecial(vector<vector<int>>& mat, int i, int j) {
        for (auto idx = 0; idx < mat.size(); idx++) {
            if (idx != i && mat[idx][j] == 1)
                return false;
        }
        for (auto idx = 0; idx < mat[0].size(); idx++) {
            if (idx != j && mat[i][idx] == 1)
                return false;
        }
        return true;
    }
};