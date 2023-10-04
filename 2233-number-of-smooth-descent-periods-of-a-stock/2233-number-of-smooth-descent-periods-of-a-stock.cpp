class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        if (prices.size() == 1)
            return 1;
        long long res = 0;
        int len = 1;
        for (auto i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] != 1) {
                res += getTriangleNumber(len);
                len = 1;
                continue;
            }
            len++;
        }
        res += getTriangleNumber(len);

        return res;
    }

    inline long long getTriangleNumber(long long n) {
        if (n < 1)
            return 1;
        if (n == 2)
            return n + 1;
        return n * (n + 1) / 2;
    }
};