class Solution {
    int find(int idx, vector<vector<int>>& jobs, vector<int>& startTime, int n,
             vector<int>& dp) {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        return dp[idx] =
                   max(jobs.at(idx).back() +
                           find(lower_bound(begin(startTime), end(startTime),
                                            jobs.at(idx)[1]) -
                                    startTime.begin(),
                                jobs, startTime, n, dp),
                       find(idx + 1, jobs, startTime, n, dp));
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = size(startTime);
        vector<vector<int>> jobs;
        vector<int> dp(n, -1);

        for (auto i = 0; i < n; i++)
            jobs.push_back({startTime.at(i), endTime.at(i), profit.at(i)});
        sort(begin(jobs), end(jobs));
        sort(begin(startTime), end(startTime));

        return find(0, jobs, startTime, n, dp);
    }
};