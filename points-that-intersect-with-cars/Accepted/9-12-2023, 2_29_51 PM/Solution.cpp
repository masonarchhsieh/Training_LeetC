// https://leetcode.com/problems/points-that-intersect-with-cars

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        bool cars[101] = { false };

        for (auto i : nums) {
            for (auto j = i.front(); j <= i.back(); j++)
                cars[j] = true;
        }

        return count(cars, cars + 101, true);
    }
};