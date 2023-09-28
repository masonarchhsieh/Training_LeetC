// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        if (numRows > 0)
            helper(res, 0, numRows);
        
        return res;
    }
    
    void helper(vector<vector<int>>& tri, int itr, int rows) {
        if (rows <= 0)
            return;
        
        vector<int> temp;
        if (itr <= 1) {
            temp.push_back(1);
            if (itr == 1)
                temp.push_back(1);
            tri.push_back(temp);
            helper(tri, ++itr, --rows);
        } else  {
            temp.push_back(1);
            for (int i=1; i<tri[itr-1].size(); i++) {
                temp.push_back(tri[itr-1][i-1] + tri[itr-1][i]);               
            }
            temp.push_back(1);
            tri.push_back(temp);
            helper(tri, ++itr, --rows);
        }
        
    }
};