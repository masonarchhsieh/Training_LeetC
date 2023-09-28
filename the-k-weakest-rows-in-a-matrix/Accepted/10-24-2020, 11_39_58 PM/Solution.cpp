// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> row;
        
        for (int i=0; i<mat.size(); i++) {
            int sum = 0;
            for (int j=0; j<mat[i].size(); j++) {
                sum += mat[i][j];
            }
            pair<int, int> record = make_pair(sum, i);
            row.push_back(record);
        }
        
        sort(row.begin(),row.end());
        vector<int> res;
        res.assign(k, -1);
        for (int i=0; i<k; i++) {
            res[i] = row[i].second;
        }
        
            
        return res;
    }
};