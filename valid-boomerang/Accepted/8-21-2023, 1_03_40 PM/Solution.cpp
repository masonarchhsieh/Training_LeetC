// https://leetcode.com/problems/valid-boomerang

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        for (auto i = 2; i < points.size(); i++) {
            if ((points[i][0] - points[i-1][0]) * (points[i-1][1] - points[i-2][1]) != (points[i-1][0] - points[i-2][0]) * (points[i][1] - points[i-1][1]))
                return true;
        }
        return false;
    }
};