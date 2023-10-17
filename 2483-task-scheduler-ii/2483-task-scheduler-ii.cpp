class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> next_availableT;
        long long time = 0;

        for (auto i = 0; i < size(tasks); i++) {
            time = max(time + 1, next_availableT[tasks[i]]);
            next_availableT[tasks[i]] = time + space + 1;
        }

        return time;
    }
};