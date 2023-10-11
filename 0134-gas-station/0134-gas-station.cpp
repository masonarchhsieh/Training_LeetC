class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = size(gas);
        int sum = 0;
        for (auto i = 0; i < n; i++) {
            gas[i] = gas[i] - cost[i];
            sum += gas[i];
        }

        if (sum < 0)
            return -1;
        auto l = 0, r = 1;
        auto cnt = gas[0];
        for (l = 0, r = 1; r < n && l != r; r++) {
            while (cnt < 0 && l < r) {
                cnt -= gas[l++];
            }
            cnt += gas[r];
        }


        return l;
    }
};