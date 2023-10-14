class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, prefix_sum = 0;

        for (auto i : gain) {
            prefix_sum += i;
            res = max(res, prefix_sum);
        }
        return res;
    }
};