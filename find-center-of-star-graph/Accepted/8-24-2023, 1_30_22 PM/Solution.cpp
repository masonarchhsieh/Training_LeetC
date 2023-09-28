// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> m;
        for (auto i = 0; i < edges.size(); i++)
            for (auto j = 0; j < edges[i].size(); j++) {
                m[edges[i][j]]++;
            }
        for (auto i : m)
            if (i.second == edges.size())
                return i.first;
        
        return -1;
    }
};