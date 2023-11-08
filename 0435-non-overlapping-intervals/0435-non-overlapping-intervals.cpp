class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int overlaps = 0;
        sort(begin(intervals), end(intervals));
        int n = size(intervals), tmp = intervals.front().back();

        for (auto i = 1; i < n; i++) {
            if (tmp > intervals[i][0]) {
                overlaps++;
                tmp = min(tmp, intervals.at(i).back());
            } else {
                tmp = intervals.at(i).back();
            }
        }

        return overlaps;
    }
};