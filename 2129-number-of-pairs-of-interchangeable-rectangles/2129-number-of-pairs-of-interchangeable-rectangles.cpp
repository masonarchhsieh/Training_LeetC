class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long res = 0;
        unordered_map<double, long long> m;

        for (auto i = 0; i < rectangles.size(); i++) {
            double ratio1 = (double) rectangles[i][0] / (double) rectangles[i][1];
            m[ratio1]++;
        }

        for (auto i : m) {
            if (i.second == 1)
                continue;
            res += i.second * (i.second - 1) / 2;
        }


        return res;
    }
};