// https://leetcode.com/problems/destination-city

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        for (auto i = 0; i < paths.size(); i++) 
            m[paths[i][0]] = paths[i][1];
        for (auto i : m)
            if (m.find(i.second) == m.end())
                return i.second;

        return "";
    }
};