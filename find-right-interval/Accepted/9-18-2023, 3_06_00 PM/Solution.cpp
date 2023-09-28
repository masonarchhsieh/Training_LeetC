// https://leetcode.com/problems/find-right-interval

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res(intervals.size());
        map<int, int> m;
        for (auto i = 0; i < intervals.size(); i++) {
            m[intervals[i][0]] = i;
        }
        for (auto i = 0; i < intervals.size(); i++) {
            res[i] = (m.lower_bound(intervals[i][1]) != end(m))?
                    m.lower_bound(intervals[i][1])->second : -1;
        }

        return res;
    }
};