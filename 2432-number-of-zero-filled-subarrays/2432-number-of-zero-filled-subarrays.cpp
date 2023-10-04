class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int zeros = 0;

        for (auto i = 0; i < nums.size(); i++) {
            if (nums.at(i) != 0) {
                res += getTriangleNumber(zeros);
                zeros = 0;
                continue;
            }
            zeros++;
        }
        res += getTriangleNumber(zeros);
        return res;
    }

    long long getTriangleNumber(long long n) {
        if (n < 2)
            return n;
        return n * (n + 1) / 2;
    }
};