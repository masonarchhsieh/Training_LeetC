// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        if (timeSeries.size() == 1)
            return duration;

        for (auto i = 1; i < timeSeries.size(); i++) {
            if (timeSeries[i] - timeSeries[i - 1] > duration - 1)
                res += duration;
            else if (timeSeries[i] - timeSeries[i - 1] <= duration - 1)
                res += timeSeries[i] - timeSeries[i - 1];
                    
        }
        res += duration;
        return res;
    }
};