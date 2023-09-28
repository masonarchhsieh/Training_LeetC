// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> sorted_intervals;
        sort(intervals.begin(), intervals.end());      
        
        for (int i=0; i<intervals.size(); i++) {
            int j=i+1;
            int temp_max = intervals[i][1];
            while (j < intervals.size() && intervals[j][0] <= temp_max) {
                if (intervals[j][1] >= temp_max)
                    temp_max = intervals[j][1];
                j++;
            }
            sorted_intervals.push_back(vector<int>{intervals[i][0], temp_max});
            i = j-1;            
        }
        
        
        
        return sorted_intervals;
    }
};