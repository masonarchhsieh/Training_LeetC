class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = size(intervals);

        intervals.push_back(newInterval);
        sort(begin(intervals), end(intervals));

        vector<vector<int>> res;
        res.push_back(intervals.front());

        for (auto i = 1; i <= n; i++) {
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals.at(i));
        }

        return res;
    }
};