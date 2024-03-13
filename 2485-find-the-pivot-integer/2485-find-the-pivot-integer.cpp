class Solution {
public:
    int pivotInteger(int n) {
        int r_sum = n * (n + 1) / 2;
        int sum = 0;

        for (auto i = 1; i <= n; i++) {
            sum += i;
            if (sum == r_sum - sum + i) {
                return i;
            }
        }
        return -1;
    }
};