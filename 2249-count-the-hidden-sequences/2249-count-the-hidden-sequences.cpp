class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long local_min = differences.front(), local_max = differences.front();
        long long prefixSum = 0;
        for (int i : differences) {
            prefixSum += i;
            local_min = min(prefixSum, local_min);
            local_max = max(prefixSum, local_max);
        }
        int start = lower, end = upper;
        if (local_min < 0)
            start += abs(local_min);
        if (local_max > 0)
            end -= local_max;

        cout << local_min << ", " << local_max << endl;
        cout << start << ", " << end << endl;

        return (end < start)? 0 : end - start + 1;
    }
};