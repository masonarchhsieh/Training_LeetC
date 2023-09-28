// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_set<int> s;
        for (auto i : ranges) {
            for (auto j = i[0]; j <= i[1]; j++) {
                s.insert(j);
            }
        }

        for (auto i = left; i <= right; i++) {
            if (s.find(i) == s.end())
                return false;
        }

        return true;
    }
};